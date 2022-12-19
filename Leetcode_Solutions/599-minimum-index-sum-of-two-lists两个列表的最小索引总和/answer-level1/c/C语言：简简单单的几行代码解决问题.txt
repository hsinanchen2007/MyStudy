

```
class Solution
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        vector<string> res;
        int index = 0;
        int top1 = 0;//用来记录第一次匹配到的list1的下标
        int top2 = 0;//用来记录第一次匹配到的list2的下标
        for (int i = 0; i < list1.size(); ++i)
            for (int k = 0; k < list2.size(); ++k)
                if (list1[i] == list2[k])
                {
                    res.push_back(list1[i]);
                    index = i+k;
                    top1  = i+1;
                    top2  = k-1;
                    i     = list1.size();//不用比了，如果继续按照这种方法比，后面的index
                    break;               //肯定比当前的index大
                }
        while (top1 < list1.size() && top2 >= 0)
        {                                      //一个向前，一个向后才能保证index等于第一个
            if (list1[top1] == list2[top2])    //共同喜爱的餐厅的值
                res.push_back(list1[top1]);
            ++top1;//一个向前
            --top2;//一个向后
        }
        return res;
    }
};
```
