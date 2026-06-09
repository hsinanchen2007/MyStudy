从结果出发，每次选择其中最大的一个数反推该数应该的值。
举个例子： 9  17  5
则最大值为17，反推出来17原来的位置是3。
新问题是： 9  3   5
则最大值为9，反推出9原来的位置是1。
新问题是： 1  3  5
则最大值为5，反推出5原来的位置是1。
新问题是： 1  3  1
则最大值为3，反推出3原来当前位置是1。
最后变为： 1  1  1
返回 true

其中找到最大元素是通过大顶堆优先队列来实现，而且每次新产生的数必须大于等于1，否则为false

```C++
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0;
        priority_queue <int,vector<int>,less<int> > q; 

        for(int i = 0; i < target.size(); i++)
        {
            q.push(target[i]);
            sum += target[i];
            if(target[i] < 1)
                return false;
        }

        while(sum > target.size())
        {
            int max = q.top();
            q.pop();
            long temp = sum - max;
            temp = max - temp;
            sum = sum - max + temp;
            if(temp < 1)
                return false;
            q.push(temp);
        }
        if(sum == target.size())
            return true;
        else
            return false;
    }
};
```