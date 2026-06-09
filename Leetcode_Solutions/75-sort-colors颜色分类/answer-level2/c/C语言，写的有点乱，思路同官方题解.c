//交换指针指向的值；
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void sortColors(int* nums, int numsSize){
    //pi为起始指针，pe为末尾指针，pm为中间指针；如果pi（pe）指向的值为0（2），会向前（后）移动一位；
    int *pi,*pe,*pm;
    //如果数组只有一个或者为空，直接返回数组
    if ( numsSize > 1 ){
        pi = nums;
        pe = (nums + numsSize - 1);
        //将pe指针从末尾移动到第一个非2的地方。如果移动到了pi则直接返回nums
        while(*pe==2){
            if(pe>pi){
                pe--;
            }else{
                return nums;
            }
        }
        //同pe
        while(*pi==0){
            if(pi<pe){
                pi++;
            }else{
                return nums;
            }
        }
        pm = pi;
        //主循环
        while (pm <= pe){
            //每进行一次pi、pe和pm的互换，pm向前移动一次。
            if ( *pm == 2 ){
                swap ( pm ,pe );
                while ( *pe == 2 &&pe > pi){
                    pe --;
                }
            }
            if ( *pm == 0 ){
                swap ( pm , pi );
                if ( pi< pe){
                    pi ++;
                }
            }
                pm++;
            
        }
    }
    return nums;
}
