这道题的左括号可以看做放在那里不动的，我们只需要考虑右括号的位置即可，在这里我设立了一个nums数组，占用了n+1个int，如果n=5,less=5,nums[4] = 2，那么就代表着在第四个左括号后面我们可以放置2个右括号。

需要注意的是，我们设立了一个**less**来表示剩余的可使用的括号，如果n=5,less=3，nums[4]最大只能够是1，因为前面已经使用了3个,还剩两个右括号可以使用，我们必须为第五个括号后面留一个括号。

这道题最难的其实就是如何排序了，用数组表示右括号可以抽象的更加使人容易理解。

拿n=3举例，nums可以有五种情况：
0,0,3
0,1,2
0,2,1
1,0,2
1,1,1
其中1,0,2代表着第一个左括号后有一个右括号，第二个左括号后面没有右括号，第三个左括号后面有两个右括号，也就是**()(())**这种组合，0,0,3代表的则是((()))这种情况
```
int top = 0;//用来记录有几种情况
void parentheses(int *nums,char **rear, int n,int less,int max)
{
    if( n < max ){
    	int less1=less;//less是被传递来的，不可改变，需用来限制nums[n]的上限
        while( nums[n] <= n-(max-less) ){//这里是nums[n]可达到的最大值，如果less=max，最大值为n也就是当前位置
            parentheses(nums,rear,n+1,less1,max);
            nums[n]++;
            less1--;
        }
        nums[n] = 0;
    }
    if( n == max ){
        rear[top] = (char *)malloc((max*2+1)*sizeof(char));
        int i=0,j=0,l=0;
        nums[n] = less;//最后一个左括号后面的右括号为less个
        for( i=1; i<=max; i++ ){
            rear[top][j++] = '(';
            while( l < nums[i] ){
                rear[top][j++] = ')';
                l++;
            }
            l = 0;
        }
        rear[top][j] = '\0';
        top++;
    }

}

char ** generateParenthesis(int n, int* returnSize){
    top = 0;
    int i=0,sum=1;
    for( i=1; i<=n; i++ ) sum *= i;
    int *nums = (int *)calloc((n+1),sizeof(int));//这里的nums[0]未被使用，为了方便表示只用1-n
    char **rear = (char **)malloc(sum*sizeof(char *));
    parentheses(nums,rear,1,n,n);
    *returnSize = top;
    return rear;
}
```
