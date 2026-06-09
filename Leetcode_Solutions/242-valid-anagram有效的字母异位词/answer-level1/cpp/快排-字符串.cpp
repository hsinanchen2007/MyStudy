# 知识点
1）快排

# 解法
1）将s和t排序后比较是否相同
快排：每次基准值取第一个数，大于基准值的数放右边，小于基准值的放左边，这样一轮后再分左右分别递归进行下去。
```
void sortStr(int low,int high,string &array){
    if(low>=high)return;//注意会出现low>high的情况，注意排除
    int temp=array[low],left=low,right=high;
    //大于基准值的数放右边，小于基准值的放左边，每次基准值去第一个数
    while(left<right){
        //right->left
        while(left<right){
            if(array[right]<temp){
                array[left++]=array[right];//把array[left]这个坑填上，array[right]形成了一个新的坑
                break;
            }
            else
                right--;
        }
        //left->right;
        while(left<right){
            if(array[left]>temp){
                array[right--]=array[left];//把array[right]这个坑填上，array[left]形成了一个新的坑
                break;
            }
            else
                left++;
        }
    }
    array[left]=temp;
    //处理基准值左侧
    sortStr(low,left-1,array);
    //处理基准值右侧
    sortStr(left+1,high,array);
}

bool isAnagram(string s, string t) {
    if(s.size()!=t.size())return false;
    sortStr(0,s.size()-1,s);
    sortStr(0,t.size()-1,t);
    return s==t;
}
```

2）统计不同字符的数量
开一个26大小数组charNum[26]，统计s中各个字符的数量charNum[s[i]]++，然后再考察t,对每个字符进行charNum[t[i]]--，并不断判断charNum[t[i]]--是否小于0,小于即错。
