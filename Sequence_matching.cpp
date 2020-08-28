#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class DynamicSafeArray
{
	
		char *data;
		char *sequence;
		int size;
	public:	
	 DynamicSafeArray()
	 {
	 	data=0;
	 	size=0;

	 }
	 DynamicSafeArray(int s)
	 {
	 	size=s;
	 	data=new char[s];
	 	sequence=new char[100];
	 
	 }
	 void set_data(char *p)
	 {
	 	size=strlen(p);
	 	data=new char[size];
	 	data=p;
	 	sequence=new char[100];
	 memset(sequence,0,sizeof(sequence));


       
	 	
	 }
	 
	  DynamicSafeArray (const  DynamicSafeArray &obj)
	  {
	  	  size=obj.size;
		  data=new char[size];
		  copy(obj.data,data+size,data);
	  	   
	}
	char &operator [](int i)const
	{
		
				return data[i];
		
	}

	DynamicSafeArray &operator =(const DynamicSafeArray &obj)
	{
	     if(this!=&obj)
		 {
		    delete []data;
		    data=new char[obj.size];
		    size=obj.size;
			
			copy(obj.data,data+size,data);
			return *this;
			 	
		}	
		else return *this;
	  	
	}
	

  friend ostream& operator <<(ostream&out,DynamicSafeArray &obj)
{

	
	  for(int i=0;i<obj.size;i++)
	  {
	  	 out<<obj.data[i];
      }
      
    

	return out;
}

friend istream& operator >>(istream&in,DynamicSafeArray &obj)
{
	
	
	for(int i=0;i<obj.size;i++)
	 in>>obj.data[i];
	
	return in;
}
 
	
	~ DynamicSafeArray()
	{
	    if(data!=0)
		delete[]data;
		data=0;	
		
	}
	
	friend void match_sequence(DynamicSafeArray&,DynamicSafeArray&);
	
};

void match_sequence(DynamicSafeArray &str1,DynamicSafeArray &str2)
{
  string temp1="",temp2="",temp3="";
  int i=0,j=0,x=0;
  
  ofstream infile("output.txt");
  
  
     while(i<str1.size)
     {
     	
     	if(str1.data[i]==str2.data[j])
     	{
     		temp2=str2.data[j];
     		temp1.append(temp2);
     		i++;
     		j++;
     	}
     	else if(str1.data[i]==str2.data[j-1])
     	{
     	   temp2="*";
		   temp1.append(temp2);	
		   i++;
		   infile<<temp1;
		   temp1="";
		  
     	}
     	else
     	{
     		
     	   if(strlen(temp1.c_str())>strlen(temp3.c_str()))
			{
		     
			   temp3="";
			   temp3=temp1; 
			   temp1="";
			 
		    }
		      x++;
		      i=x;
			  j=0;
			  temp1="";
		 
     		
     	}
     	
    }
    
    infile<<temp3;
    if(temp1!="");
    temp3=temp1;
    infile<<temp3;
  
   	
   
   
  
   
   infile.close();
}


int main()
{
    ifstream outfile("A1P2IO2.txt"); //input file
   DynamicSafeArray D1,D2;
  char *str1=new char[80],*str2=new char[80];
    outfile>>str1;
    
    D1.set_data(str1);
    outfile>>str2;
   D2.set_data(str2);

   outfile.close();
 match_sequence(D1,D2);
return 0;
	
}


