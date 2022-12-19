*3种方法：库函数+快排+优先队列(小顶堆)*

**1. 库函数**
简单粗暴采用sort(nums.begin(),nums.end())
然后返回倒数第k个数字即可
虽说无耻，但的确速度效率都挺好

**2. 快排**
快排的思想是：找准一个基准，把小于基准的全部丢基准左边，把大于基准的全部丢在基准的右边
完成一个基准的位置后，基准这个地方的值是不会改变的
按照快排，应该是对基准的左边和右边进行递归，实现快排

这里就可以借助快排的思想，
既然完成一次基准的排序后，基准这个地方的值是确定的
即nums[基准值的位置]一定是第(基准的位置)小的元素(是按升序排列，最左边最小)
所以我们就判断这个最后(基准值的位置)是不是(nums.size()-k)即可
如果不是，我们只需对基准的左半部分或右半部分进行递归
直到找到(基准值的位置)是(nums.size()-k)即可

**3. 优先队列(小顶堆)**
先介绍下[优先队列](https://blog.csdn.net/weixin_36888577/article/details/79937886)
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
就是说q这个队列里面的元素都是按升序排列好的(队头是最小的)
那么我们只需要不停的把元素放入优先队列
它会自动排序
然后稳定好队列的长度为k即可
如果长度超过k了，那就出队队头，即队列中最小的元素
最后返回队列的队头，即为第k大的元素

**总结**
库函数最快，复杂度O(nlogn)
快排平均复杂度O(nlogn)，最差时候会变成O(n^2)
优先队列的方法适合于数据不断更新的时候，会更有利，复杂度我感觉也是O(nlogn)，因为队列中也有排序

```
代码1:库函数
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return *(nums.end()-k);
    }
};
```

```
代码2：快排
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index=nums.size()-k;
        return quick_sort(nums,0,nums.size()-1,index);
    }
    int quick_sort(vector<int>& nums,int low,int high,int& index)
    {
        int povitkey=nums.at(low),left=low,right=high;
        while (left<right)
        {
            while (left<right)
                if (nums.at(right)<povitkey)
                {
                    nums.at(left)=nums.at(right);
                    ++left;
                    break;
                }
                else
                    --right;
            while (left<right)
                if (nums.at(left)>povitkey)
                {
                    nums.at(right)=nums.at(left);
                    --right;
                    break;
                }
                else
                    ++left;
        }
        nums.at(left)=povitkey;
        if (left==index)
            return povitkey;
        else if (left>index)
            return quick_sort(nums,low,left-1,index);
        else
            return quick_sort(nums,left+1,high,index);
    }
};
```

```
代码3：优先队列/小顶堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //升序的优先队列
        priority_queue <int,vector<int>,greater<int> > ascending;
        for (int &i:nums)
        {
            ascending.push(i);
            if (ascending.size()>k)
                ascending.pop();
        }
        return ascending.top();
    }
};
```

如果觉得好可以去[个人github仓库](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution)给个星星，有不懂可以评论区问




