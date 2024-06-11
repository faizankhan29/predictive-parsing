//To Implement Predictive Parsing
 #include<string.h>
 #include<stdio.h>
 #include<stdlib.h>
 char b[10];
 int top=-1;
 int i;
 void error1(){
 printf("\n\nSyntax Error");
 }
 void push(char k[]) //Pushes The Set Of Characters on to the Stack
 {
   for(i=0;k[i]!='\0';i++)
   {
     if(top<9)
	{
		++top;
     		b[top]=k[i];
	}
   }
 }
 char Top_Stack()        //Returns TOP of the Stack
 {
	if(top<0)
		return '\0';
	else
   		return b[top];
 }
 void pop()       //Pops 1 element from the Stack
 {
   if(top>=0)
     b[top--]='\0';
 }
 void show_stack()  //Displays Elements Of Stack
 {
   for(i=0;i<=top;i++)
     printf("%c",b[i]);
 }
 void show(char p[],int m) //Displays The Present Input String
 {
   int l;
   printf("\t");
   for(l=m;p[l]!='\0';l++)
     printf("%c",p[l]);
printf("\t");
 }
 char* stack(){
 return b;
 }
char *strrev(char *str)			//Reverses a string using pointers
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
 int main()
 {
   char in[20],r[20],nonter,an;
   int ir,ic,j=0,k;
   char t[5][6][10]={"$","$","TH","$","TH","$",                                                   //Predictive Parsing Table
 		   "+TH","$","e","e","$","e",
 		   "$","$","FU","$","FU","$",
 		   "e","*FU","e","e","$","e",
 		   "$","$","(E)","$","i","$"};
   
   printf("\nEnter any String (Please append with a $):\n");
   fgets(in,sizeof(in),stdin);
   printf("Stack\tInput\tOutput\n\n");
   push("$E");							//Pushing start symbol with $
   show_stack();
   printf("\t%s\n",in);
   for(j=0;in[j]!='\0';)
   {
   if(Top_Stack()==an)
       {
 	pop();
 	show_stack();
 	show(in,j+1);
 	printf("\t\tPOP\n");
 	j++;
       }
     an=in[j];
     nonter=Top_Stack();					//Assigning row numbers to the respective non-terminals
       if(nonter=='E')ir=0;
       else if(nonter=='H')ir=1;
       else if(nonter=='T')ir=2;
       else if(nonter=='U')ir=3;
       else if(nonter=='F')ir=4;
       else {
 	    error1();
 	    break;
 	    }
       if(an=='+')ic=0;						//Assigning column numbers to the respective non-terminals
       else if(an=='*')ic=1;
       else if(an=='(')ic=2;
       else if(an==')')ic=3;
       else if((an>='a'&&an<='z')||(an>='A'&&an<='Z'))
	{
		ic=4;
		an='i';
	}
       else if(an=='$')ic=5;					
       strcpy(r,strrev(t[ir][ic]));				//Copying reverse of string to the stack
       strrev(t[ir][ic]);
       pop();
       push(r);
       if(Top_Stack()=='e')
       {
 	pop();
 	show_stack();
 	show(in,j);
 	printf("\t%c->%c\n",nonter,238);
       }
       else{
       show_stack();
       show(in,j);
       printf("\t%c->%s\n",nonter,t[ir][ic]);
       }
       if(Top_Stack()=='$'&&an=='$')				//Denotes end of string
       break;
       if(Top_Stack()=='$'){
 	error1();
 	break;
 	}
       }
       k=strcmp(stack(),"$");
	//int len=strlen(in);
	//printf("%d\t%d\t%d",k,i,len);
       if(k==0)							//Compare and display whether string is accepted or not
     printf("\n Given String is accepted\n");
     else
     printf("\n Given String is not accepted\n");
   return 0;
 }

