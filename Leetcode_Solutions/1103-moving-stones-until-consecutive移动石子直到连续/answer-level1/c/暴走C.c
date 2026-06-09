疑问：a,b,c可以相等不？应该是会有相等的情况的，所以一样要考虑进去

    int* numMovesStones(int a, int b, int c, int* returnSize){
        int* p = (int *)malloc(2*sizeof(int));
        p[0] = 0;
        p[1] = 0;
        *returnSize = 2;
        int tmp;
        
        //先排序使 a<b<c
        if(a > b){
            tmp = a;
            a = b;
            b = tmp;
        }
        
        if(a > c){
            tmp = a;
            a = c;
            c = tmp;
        }
        
        if(b > c){
            tmp = b;
            b = c;
            c = tmp;
        }
        
        //最少移动次数，分多种情况
        if((b-a) == 2 || (c-b) == 2){
            p[0] = 1;
        }else if((b-a) <= 1 && (c-b) <= 1){
            p[0] = 0;
        }else if((b-a) <= 1 || (c-b) <= 1){
            p[0] = 1;
        }else{
            p[0] = 2;
        }
        
        //最多移动次数，就是a与b之间的数的个数+b与c之间数的个数
        p[1] = ((b-a-1) != 0 ? (b-a-1): 0)+((c-b-1) != 0 ? (c-b-1): 0);
        
        return p;
        
    }