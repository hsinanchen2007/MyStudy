### 解题思路
此处撰写解题思路
![t.png](https://pic.leetcode-cn.com/f675d156f49deebbf30ff572d620a9228061bb23cba5bcfd71d5595f1789d400-t.png)
用时间换空间的做法，只需要将index序列sort一下，然后从字符串的尾部开始替换到头部，就可以直接在原串上进行操作，而无需任何其他修改！！！
### 代码
class Solution {
public:
    // void quickSort(vector<int> &indexes,vector<string> &sources,vector<string>&targets,int left,int right)
    // {
    //     int i=left,j=right;
    //     int temp3=indexes[i];
    //     string temp=sources[i];
    //     string temp2=targets[i];
    //     if(left<right)
    //     {
    //         while(i<j)
    //         {
    //             while(indexes[j]>=temp3&&j>i)
    //                 --j;
    //             if(j>i)
    //             {
    //                 indexes[i]=indexes[j];
    //                 sources[i]=sources[j];
    //                 targets[i]=targets[j];
    //             }
    //             while(indexes[i]<=temp3&&i<j)
    //                 ++i;
    //             if(i<j)
    //             {
    //                 indexes[j]=indexes[i];
    //                 sources[j]=sources[i];
    //                 targets[j]=targets[i];
    //             }
    //         }
    //         indexes[i]=temp3;sources[i]=temp;targets[i]=temp2;
    //         quickSort(indexes,sources,targets,left,i-1);
    //         quickSort(indexes,sources,targets,i+1,right);
    //     }
    // }
    int Partition(vector<int> &now,int left,int right,vector<string> &sources,vector<string> &targets)
    {
    int temp=now[left];string temp1=sources[left];string temp2=targets[left];
    while(left<right)
    {
        while(now[right]>=temp&&left<right)
            --right;
        now[left]=now[right];
        targets[left]=targets[right];
        sources[left]=sources[right];
        while(now[left]<=temp&&left<right)
            ++left;
        now[right]=now[left];
        targets[right]=targets[left];
        sources[right]=sources[left];
    }
    now[left]=temp;sources[left]=temp1;targets[left]=temp2;
    return left;
}
void quickSort(vector<int> &res,vector<string> &sources,vector<string> &targets,int left,int right)
{
    if(left<right)
    {

        int temp=Partition(res, left, right,sources,targets);
        quickSort(res,sources,targets, left, temp-1);
        quickSort(res,sources,targets, temp+1, right);
    }
}
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string temp=S;int lt=indexes.size()-1;
        quickSort(indexes,sources,targets,0,lt);
        for(int i=indexes.size()-1;i>=0;--i)
        {
            if(temp.find(sources[i],indexes[i])==indexes[i])
                S=S.substr(0,indexes[i])+targets[i]+S.substr(indexes[i]+sources[i].size());
        }
        return S;
    }
};

```