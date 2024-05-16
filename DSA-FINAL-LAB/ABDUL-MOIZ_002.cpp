// SEATNO-- B22110106002 
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


// FIRST WE CREATE A STRUCT FOR THE DOUBLE LINKED LIST:-
struct Record{
    int data;
    int index;
    Record* next;
    Record* prev;
};


// NOW WE MAKE THE INSERT FUNCTION THAT FOOLOW THE PROPERTY OF DOUBLE LINKED LIST
// AND STORE INDEX OF THE REPECTIVETLY NODE IN THE LINKED LIST
void Insert(Record**head_ref , int data){
    // FIRST WE ALLOCATE THE MEMORY AND STORE DEFAULT VALUE IN IT
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data=data;
    ptr->index=0;
    ptr->next=NULL;
    ptr->prev=NULL;

    // FIRST CASE IF THE HEAD IS EQUAL TO NULL:-
    if(*head_ref==NULL){
        // index is already equal to zero , prev and next is also null
        *head_ref=ptr;
    }

    // SECOND CASE WHAT IF THE HEAD IS NOT EQUAL TO ZERO:-
    else{
        // store into another pointer so our head in not lost in the memory
        Record* curr = *head_ref;
        // WHY CURR->NEXT --- BEACUSE WE WANT TO LOCATE LAST NODE OF THE LIST
        while (curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
        // curr->index+1 == ptr->index
        ptr->index=curr->index+1;
        ptr->prev=curr;
    }
}


// NOW WE HAVE TO MAKE A PRINT FUNCTION INORDER TO CHECK THAT YOUR INSERTION 
// IS WORKING CORRECTLY OR NOT 
void print(Record**head_ref){
    if(*head_ref==NULL){
        cout << "Sorry! But double linked list is empty" << endl;
    }
    Record* curr = *head_ref;
    while (curr!=NULL){
        cout << endl;
        cout << "The index of thr node is: " << curr->index << " :" << endl;
        cout << "The data of the node is: " << curr->data << endl;
        curr=curr->next;
        cout << endl;
    }
    cout << endl;
}

// WHEN WE COPY THE LINKED LIST TO ARRAY WE HAVE TO DELETE PREVIOUS LIST 
void delete_list(Record**head_ref){
    if(*head_ref==NULL){
        cout << "The Double linked list is empty " << endl;
    }
    else{
        Record* curr = *head_ref;
        Record* all;
        while (curr!=NULL){
            all=curr;
            free(curr);
            curr=curr->next;
        }
        *head_ref=NULL;
    }
}


// NOW AS WE ALREADY HAS THE ADDRESS OF THE FIRST NODE WHICH IS HEAD NODE OF THE DOUBLE LINKED LIST
// BUT NOW WE ALSO HAVE TO STORE THE ADDRESS OF THE LAST NODE
Record* Last_node_address(Record**head_ref){
    if(*head_ref==NULL){
        cout << "The Double linked list is empty " << endl;
    }
    else{
        Record* curr = *head_ref;
        while (curr->next!=NULL){
            curr=curr->next;
        }
        return curr;
    }
}

// NOW WE HAVE TO GET THE TOTAL NO OF NODE PRESENT IN THE LINKED LIST
// FOR THAT WE CREATE A FUNCTION AND STORE IN INTO VARIABLE AND THAN RETURN THE VALUE OF THE VARIABLE
int Toatl_Node_Of_A_List(Record**head_ref){
    if(*head_ref==NULL){
        cout << "The Double linked list is empty " << endl;
    }
    else{
        Record* curr = *head_ref;
        int count=0;
        while (curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
}

// INORDER TO SORT THE LINKED LIST IT IS DIFFICULT TO APPLY ON IT 
// SO WE COPY THE LINKED LIST INTP THE ARRAY AND THAN SORT THE ARRAY WITH ANY SORT ALGO 
// THAN AGAIN COPY THE ARRAY INTO THE LINKED LIST


// FIRST WE HAVE TO FIND OUT THE LENGTH OF THR LINKED LIST SO THAT WE CAN MAKE THAT SIZE
// OF ARRAY TO STORE NODE
int length_of_a_list(Record**head_ref){
    if(*head_ref==NULL){
        cout << "The Double linked list is empty " << endl;
    }
    else{
        Record* curr = *head_ref;
        int len=0;
        while (curr->next!=NULL){
            len++;
            curr=curr->next;
        }
        return len;
    }
}

// NOW WE COPY THE NODE OF THE LINKED LIST INTO THE ARRAY BY CREATING ARRAY OF LEN()
// FOR THAT WE HAVE TO CREATE FUNCTION TO DO IT
void convert_list_to_array(Record** head_ref, int* arr) {
    Record* curr = *head_ref;
    int i = 0;
    while (curr != NULL) {
        arr[i] = curr->data;
        curr = curr->next;
        i++;
    }
}

// CONVERT ARRAY TO LIST FUNCTION
void convert_array_to_list(Record** head_ref, int* arr, int len) {
    delete_list(head_ref);
    for (int a = 0; a < len; a++) {
        Insert(head_ref, arr[a]);
    }
}


// EASIEST SORT --> BUBBLE SORT:-
void Bubble_Sort(int arr[] , int size){
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j <size-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

// NOW WE HAVE TO DECALRE THE ARRAY AND MAKE A FUNCTION TO CALL FOR
// SORTED DOUBLE LINKED LIST

void sorted_list(Record** head_ref) {
    int len = length_of_a_list(head_ref);
    int* arr = new int[len];
    convert_list_to_array(head_ref, arr);
    Bubble_Sort(arr, len - 1);
    convert_array_to_list(head_ref, arr, len);
    delete[] arr;
}





int main(){

    Record* head = NULL;

    int select;
    cout << "enter 0 to exit the program: " << endl;
    cout << "enter 1 to insert the data: " << endl;
    cout << "enter 2 to print the data: " << endl;
    cout << "enter 3 to print the address of the first(head) node: " << endl;
    cout << "enter 4 to print the address of the last(tail) node: " << endl;
    cout << "enter 5 to print the total number of node: " << endl;
    cout << "enter 6 to apply bubble sort on to the double list: " << endl;
    cout << "enter your choice here: ";
    cin >> select;
    cout << endl;

    while (select!=0){
        if(select==1){
            int data;
            cout << "enter the data that you want enter: ";
            cin >> data;
            Insert(&head,data);
            cout << endl;
        }
        if(select==2){
            print(&head);
            cout << endl;
        }
        if(select==3){
            cout << "The address of the first node is: " << head << endl;
            cout << endl;
        }
        if(select==4){
            cout << "The address of the last node is: " << Last_node_address(&head) << endl;
            cout << endl;
        }
        if(select==5){
            int total = Toatl_Node_Of_A_List(&head);
            cout << "The Total number of node in double linked list is: " << total << endl;
            cout << endl;
        }
        if(select==6){
            cout << "Original linked list: " << endl;
            cout << endl;
            print(&head);
            cout << endl;
            sorted_list(&head);
            cout << "Sorted linked list: " << endl;
            print(&head);
            cout << endl;
        }
        cout << "enter your choice again: ";
        cin >> select;
    }
   return 0;
}