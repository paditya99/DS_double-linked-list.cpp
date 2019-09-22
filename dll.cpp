#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

};
class linkedlist{
    private:
        Node* head,*tail;

    public:
      linkedlist(){

       head=NULL;
       tail=NULL;
    }

    void addatfront(int value){
        Node* temp=new Node();
        temp->data=value;
         if (head == NULL)
         {
          head=temp;
          head->next = NULL;
		  head->prev = NULL;
          tail=temp;
          cout<<"add at front  ";
         }

      else{
        temp->next=head;
		temp->prev=NULL;
        head->prev=temp;
        head=temp;
        cout<<"add at front  ";

      }
    }

      void addat3rdpos(int value){

         if(head==NULL  || head==tail){
           cout<<"Error !! Cannot add at 3rd position !!  ";
           return;
         }
         else{
            Node *temp=new Node();
            temp->data=value;
            temp->next=head->next->next;
            temp->prev=head->next;
            head->next->next=temp;
            head->next->next->prev=temp;
            cout<<"add at 3rd position  ";
         }
      }

      void addAfterNthPos(int pos, int value){

          if(head==NULL){
            cout<<"NOT ENOUGH NODES, CREATE THE LIST FIRST !! ";
            return;
          }
          Node *s,*temp;
          s=head;
          int i;
          for(i=0;i<pos-1;i++){
              s=s->next;
              if(s==NULL){
                cout<<"There are less than ";
                cout<<pos<<" elements.\n";
                return;
              }
          }
          temp=new Node;
          temp->data=value;
          if(s->next==NULL){
            s->next=temp;
            temp->next=NULL;
            temp->prev=s;
          }
          else{
            temp->next=s->next;
            temp->next->prev=temp;
            s->next=temp;
            temp->prev=s;
          }

          cout<<"add at Nth position  ";

      }

        void deleteafterNthpos(int pos){
           if(head==NULL){
              return;
           }

          Node *s,*temp;
          s=head;
          int i;
          for(i=0;i<pos-1;i++){
              s=s->next;
              if(s==NULL){
                return;
              }
          }
        if(s->next!=tail){
         s->next->next->prev=s;
         s->next=s->next->next;

        }
        else{
            temp=s->next;
            s->next=NULL;
            delete temp;

        }
                 }

      void addBeforeNthPos(int pos, int value){

          if(head==NULL){
            cout<<"NOT ENOUGH NODES, CREATE THE LIST FIRST !! ";
            return;
          }
          Node *s,*temp;
          s=head;
          int i;
          for(i=0;i<pos-1;i++){
              s=s->next;
              if(s==NULL){
                cout<<"There are less than ";
                cout<<pos<<" elements.\n";
                return;
              }
          }
          temp=new Node;
          temp->data=value;
          if(s->next==NULL){
            s->next=temp;
            temp->next=NULL;
            temp->prev=s;
          }
          else{
            temp->next=s;
            temp->prev=s->prev;
            s->prev=temp;
            s->prev->next=temp;
          }

          cout<<"add before Nth position  ";

      }


    void addatend(int value){


       Node* temp=new Node();
       temp->data=value;

     if (head == NULL) {
        temp->prev = NULL;
        temp->next=NULL;
        head = temp;
        tail=temp;
        return;
       }
     else{
       Node *s;
       s=head;
       while(s->next!=NULL){
        s=s->next;
       }
       temp->next=NULL;
       s->next=temp;
       temp->prev=s;
       tail=temp;

       cout<<"add at end  ";

      }
    }



      void deletefront(){
        if(head==NULL){
                return;
        }
        else{
           Node *temp;
           temp=head;
           head=head->next;
		   head->prev=NULL;
           delete temp;

        }
        cout<<"delete front  ";

     }

  void delete_last()
  {
    Node *temp;
    if(head==NULL){
        return;
    }
    else if(head==tail){
        head=NULL;
        delete head;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next = NULL;
        delete temp;

    }
  }

  void searching(int element){

        if (head == NULL)
        {
        cout<<"List is empty"<<endl;

        }
        Node *N;
        N=head;
        bool flag = false;
        while(N!=NULL)
        {
          if(N->data==element){
                cout<<"\n NUMBER FOUND";
                flag=true;
                break;

          }
          else{
                N=N->next;
          }
        }
        if(!flag){
            cout<<"\nNUMBER NOT FOUND\n";
        }
   }


    void display()
    {
        Node *N;
        N=head;
        while(N!=NULL)
        {
        cout<<N->data<<" ";
        N=N->next;
        }
    }
    void traverseback(){
        Node *N;
        N=tail;
        cout<<"reverse the list  ";
        while(N!=NULL){
            cout<<N->data<<" ";
            N=N->prev;
        }

    }

};
int main()
{
    linkedlist a;

    int choice,value;
    char c;
    int pos;
    cout<<"\t*******DOUBLY LINKED LIST OPERATIONS*******\t";

    cout<<"\n 1. add at head\n 2. add at tail\n 3. search an element\n 4. delete from head\n 5. delete from tail\n 6. add at 3rd position\n 7. reverse the list\n 8. add after Nth position\n 9. add before Nth position\n 10. delete after Nth pos\n";
    do{
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
       case 1:
          cout<<"Enter the element: ";
          cin>>value;
          a.addatfront(value);
          a.display();
          cout<<"\n";
          break;
		case 2:
		    cout<<"Enter the element: ";
          cin>>value;
          a.addatend(value);
          a.display();
          cout<<"\n";
		  break;
        case 3:
		    cout<<"Enter the element: ";
          cin>>value;
          a.searching(value);
          cout<<"\n";
          break;
        case 4:


          a.deletefront();
          a.display();
          cout<<"\n";
          break;
        case 5:
          a.delete_last();
		  a.display();
          cout<<"\n";
          break;
        case 6:
            cout<<"Enter the element: ";
          cin>>value;
          a.addat3rdpos(value);
		  a.display();

          cout<<"\n";
          break;
        case 7:
          a.traverseback();
          cout<<"\n";
          break;
        case 8:
            cout<<"Enter the Nth position after which you want to add: ";
            cin>>pos;
            cout<<"Enter the element: ";
            cin>>value;
            a.addAfterNthPos(pos,value);
            a.display();
            cout<<"\n";
            break;
        case 9:
            cout<<"Enter the Nth position before which you want to add: ";
            cin>>pos;
            cout<<"Enter the element: ";
            cin>>value;
            a.addBeforeNthPos(pos,value);
            a.display();
            cout<<"\n";
            break;
        case 10:
            cout<<"Enter the Nth position after which you want to delete: ";
            cin>>pos;

            a.deleteafterNthpos(pos);
            a.display();
            cout<<"\n";
            break;

       default:
          cout<<"WRONG INPUT, ENTER AGAION ";
          break;
     }
     cout<<"Do you want to continue? y/n : ";
     cin>>c;
     switch(c){
        case 'n':
           break;
         }
         }while(c=='y')  ;


 return 0;
}
