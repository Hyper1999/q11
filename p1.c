#include<stdio.h>
#include<stdlib.h>
#define PREV_REQ 125
#define CURR_REQ 143
int absolute(int num){
    return num>0?num:(num*-1);
}
int compare(const void * a, const void * b){
   return ( (int)a - (int)b );
}
int main(){
    int queue[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
    int i,s_index,len=sizeof(queue)/sizeof(int),dist=0,last,curr;
    qsort(queue, len, sizeof(int),compare);
    last = CURR_REQ;
    //SCAN[ELEVATOR ALGORITHM]
    //elevator going up...
    if(CURR_REQ>=PREV_REQ){
        for(i=0; i<len; i++){
            if(queue[i]>CURR_REQ){
                s_index=i;
                break;
            }
        }
        printf("Order    : %4d",last);
        for(i=s_index; i<len; i++){
            printf(", %4d",queue[i]);
            curr = queue[i];
            dist+= absolute(last-curr);
            printf("[%d]",absolute(last-curr) );
            last = curr;
        }
        for(i=s_index; i>0; i--){
            printf(", %4d",queue[i-1]);
            curr = queue[i];
            dist+= absolute(last-curr);
            printf("[%d]",absolute(last-curr) );
            last = curr;
        }
    }
    //elevator going down...
    else if(CURR_REQ<PREV_REQ){
        for(i=0; i<len; i++){
            if(queue[i]>CURR_REQ){
                s_index=i;
                break;
            }
        }
        printf("Order    : %4d",last);
        for(i=s_index-1; i>=0; i--){
            printf(", %4d",queue[i]);
            curr = queue[i];
            dist+= absolute(last-curr);
            printf("[%d]",absolute(last-curr) );
            last = curr;
        }
        for(i=s_index; i<len; i++){
            printf(", %4d",queue[i]);
            curr = queue[i];
            dist+= absolute(last-curr);
            printf("[%d]",absolute(last-curr) );
            last = curr;
        }
    }
    printf("\nDistance : %d\n",dist);
    return 0*printf("\nSUCCESSFUL EXIT\n");
}

