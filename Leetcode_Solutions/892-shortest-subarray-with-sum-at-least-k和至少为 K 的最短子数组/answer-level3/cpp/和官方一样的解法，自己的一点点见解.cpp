首先迭加一下，用sum[i+1]代表从A[0]到A[i]的和，然后要求的就是
满足sum[j]-sum[i] >= K的集合([i,j]为这个集合的元素)中 j-i 最小的那个元素

这又又又回到了那个熟悉的问题，排位问题
给每个人排座位，现在到你了，你会想这个座位一定要是递增的，为甚么？
因为如果你前面有一个比你高，再前后有一个比你矮，你肯定拿自己减去矮个的高度看>=K?，而不会拿自己-前面的前面那个高个的高度
你会自然的把前面的高个给删去，为甚么可以，因为你更矮~~，你后面的人如果比较，也会跟你比较(j-i小/位子更近)
所以还是变成递增数组/栈/队列

这里特殊的是当排到我们了，我们先确定我们前面没有高个，高个的话就踢了，然后拿自己与第一位的人去比较，因为他最矮，然后再跟第二位...
所以这里才使用了双端队列，因为排到我们时，我们要从后面剔除高个，再从前面第一位开始进行比较。


```
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        
        int n = A.size();
        vector<int> sum(n+1, 0);
        
        for(int i = 0; i < n; i++) //准备工作
            sum[i+1] = sum[i] + A[i];
        
        deque<int> de;
        int j = 0;
        int res = n+1;
        
        while(j<=n){
            
            while(!de.empty() && sum[j] <= sum[de.back()]){ //我们确定我们前面没有高个，有就踢他
                de.pop_back();
            }
            while(!de.empty() && sum[j] - sum[de.front()] >= K){ //从最前面第一位同学开始，进行比较
                res = min( res, j - de.front());
                de.pop_front();
            }
            de.push_back(j); //最后才坐下去
            j++;
        }
        if(res == n+1)
            return -1;
        else
            return res;
    }
};
```


其实如果这个数组都是正的，可以用滑动窗口

```
class Solution{
public:
    
    int minSubArrayLen(int s, vector<int>& nums){
        
        int i = 0 , j = -1;
        int sum = 0;
        int res = nums.size() + 1;               //我们用了min去取最小值，res最大是n+1，而我们数组最大长度为n，这样保证了res最后最坏的情况下会取n
        
        while( i < nums.size() ){                //不用再加1，因为 n-1 是最后一个元素，注意这里是 i 而不是 j
            
            if( sum < s && j+1 < nums.size()){   //这里要保证 j最后取到n-2，因为后面有j++会取到最后一个元素
                j++;
                sum += nums[j];
            }
            else
                sum -= nums[i++];
                                 
            if( sum >= s )                    
                res = min( res , j - i + 1);    
        }
        
        if( res == nums.size()+1 )
            return -1;
        else
            return res;
    }
};

```
