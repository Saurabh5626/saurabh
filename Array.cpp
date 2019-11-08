#include<iostream>
using namespace std;

class Array
{
	protected:
		int *Arr;
		int size;

	public:
		Array(int value=10)
		{
			cout<<"Inside Constructor\n";

			this->size=value;
			this->Arr=new int[size];
		}

		Array(Array &ref)
		{	
			cout<<"Inside copy Constructor";

			this->size=ref.size;
			this->Arr=new int[this->size];

			for(int i=0;i<this->size;i++)
			{	
				this->Arr[i]=ref.Arr[i];	
			}	
		}
		~Array()
		{
			cout<<"Inside Destructor"<<"\n";

			delete []Arr;
		}	
		inline void Accept();
		inline void Display();
};

void Array::Accept()
{
	cout<<"please Enter the Values";

	for(int i=0;i<this->size;i++)
	{
		cin>>Arr[i];
	}		

}

void Array::Display()
{
	cout<<"Elements are\n";

	for(int i=0;i<this->size;i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<"\n";
}

class Arrsearch:public Array
{
	public:
		Arrsearch(int no=10):Array(no)
	{}

		int Frequency(int);
		int SearchFirst(int);
		int SearchLast(int);
		int EvenCount();
		int OddCount();
		int SumAll();
};

int Arrsearch::SearchFirst(int value)
{
	int i=0;

	for(i=0;i<size;i++)
	{ 
		if(Arr[i]==value)
		{
			break;
		}
	}
	if(i==size)
	{
		return -1;
	}
	else
	{
		return i;
	}
}




int Arrsearch::Frequency(int value)
{
	int i=0,iCnt=0;

	for(i=0;i<size;i++)
	{
		if(Arr[i]==value)
		{
			iCnt++;
		}
	}
	return iCnt;
}

int Arrsearch::SearchLast(int value)
{
	int i=0;

	for(i=size-1;i>=0;i--)
	{
		if(Arr[i]==value)
		{
			break;
		}
	}


	if(i==-1)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

int Arrsearch::EvenCount()
{
int i=0,iCnt=0;

	for(i=0;i<this->size;i++)
	{
		if((Arr[i]%2)==0)
		{
			iCnt++;
		}
	}
	return iCnt;
}

int Arrsearch::OddCount()
{
int i=0,iCnt=0;

	for(i=0;i<this->size;i++)
	{
		if((Arr[i]%2)!=0)
		{
			iCnt++;
		}
	}
	return iCnt;
}



int Arrsearch::SumAll()
{
int i=0,sum=0;

	for(i=0;i<this->size;i++)
	{
		sum=sum+Arr[i];
	}
	return sum;
}


int main()
{
	cout<<"Inside main\n";

	Arrsearch sobj1;
	sobj1.Accept();
	sobj1.Display();

	
	Arrsearch sobj2(5);
	sobj2.Accept();
	sobj2.Display();

	int iRet=sobj2.Frequency(11);

	cout<<"Frequency is"<<iRet<<"\n";

	iRet=sobj2.SearchFirst(11);
	
	cout<<"First Occurance is"<<iRet<<"\n";


	iRet=sobj2.SearchLast(11);

	cout<<"Last Occurance is"<<iRet<<"\n";


	iRet=sobj2.EvenCount();
	cout<<"Even Count is"<<iRet<<"\n";

	iRet=sobj2.OddCount();
	cout<<"Odd Count is"<<iRet<<"\n";
			
	iRet=sobj2.SumAll();
	cout<<"sum of all elements is"<<iRet<<"\n";


	Arrsearch sobj3(sobj2);
	sobj3.Display();
	return 0;
}
