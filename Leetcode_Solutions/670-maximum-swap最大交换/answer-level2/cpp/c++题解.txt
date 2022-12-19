思路：从左到右查找数字，找到当前位置不是最大值的位置，将这个元素右侧的最大元素跟之前查找到的位置进行交换，就得到了一次交换得到的最大数值
第一步，先用一个双循环查找，当前位置不是从当前位置到最后位置的最大值的元素，
第二步，将这个元素右侧的最大元素跟之前查找到的位置进行交换
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 cpp 提交中击败了91.30%的用户

```
class Solution {
public:
    int maximumSwap(int num) {
        string temp=to_string(num);
        int index=-1;
        //第一步，先用一个双循环查找，当前位置不是从当前位置到最后位置的最大值的元素，
        for(int i=0;i<temp.size();i++)
        {
            for(int j=i+1;j<temp.size();j++)
            {
                if(temp[i]<temp[j])
                {
                    index=i;
                    break;
                }
            }
            if(index!=-1)
            break;
        }
        if(index==-1)   return num;
        char res=temp[index];
        int mm=0;
        //第二步，将这个元素右侧的最大元素跟之前查找到的位置进行交换
        for(int j=temp.size()-1;j>index;j--)
        {
            if(temp[j]>res)
            {
                res=temp[j];
                mm=j;
            }
        }
        char temp1;
        temp1=temp[index];
        temp[index]=temp[mm];
        temp[mm]=temp1;
        stringstream ss;
        ss<<temp;
        ss>>mm;
        return mm;
    }
};
```
