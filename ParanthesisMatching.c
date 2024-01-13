#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char*arr;
};
int isempty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct stack*ptr){
    if(ptr->top ==ptr->size-1 ){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack*ptr , char value){
    if(isfull(ptr)){
        printf("stack overflow\n");
    }
    else{
    ptr -> top++;
    ptr -> arr[ptr->top]= value;
    }
}

char pop(struct stack*ptr){
    if(isempty(ptr)){
        printf("stack underflow\n");
        return -1;
    }
    else{
        char value= ptr->arr[ptr->top];
        ptr-> top--;
        return value;
    }
}
int paranthesismatch(char*exp){
    struct stack*a;
    a-> size = 100;
    a-> top = -1;
    a-> arr = (char*)malloc(a->size*(sizeof(char)));

for (int i = 0; exp[i]!='\0'; i++){
if(exp[i]=='('){
    push(a,'(');
}
else if(exp[i]==')'){
    if(isempty(a)){
        return 0;
    }
    pop(a);
}
}
if(isempty(a)){
    return 1;
}
else{
    return 0;
}
}
int main(){
    char *exp = "(45)+)(4-9)";
    paranthesismatch(exp);
    if(paranthesismatch(exp)){
        printf("The paranthesis is matching\n");
    }
    else{
        printf("The paranthesis is not matching\n");
    }
    return 0;
}

