### 解题思路
做完之后，看了题解发现用排序做可能方便一点

时间 8ms 空间13MB

想法是：将每个非负整数补齐位数，使所有的数的位数都相同，再依次比较，每次取出最大数，将这个最大数原来（补齐位数前的状态）的每一位拆开，转换为char类型，加入结果中。
时间复杂度：O(n^2)

关于补齐位数：添在最后的数是该数第一位的值
先举几个例子 
1. 10 1  ----  最大整数为110
补齐 10 11 -> 11大，在结果中先加入原来的1，再加入10
2. 3 30 34 5 9 ---- 最大整数为9534330
补齐 33 30 34 55 99 -> 依次找最大，将原数加入结果
补齐位数再比较是为了保证得到最大的数，如34330
3. 需要注意的一种情况
121 12
补齐后为121 121，这时需要比较两者的原数相连后的大小，即12112和12121比较，取大的那种
830 8308
补齐后为8308 8308，这时需要比较两者的原数相连后的大小，即8308308和8308830比较，取大的那种
4. 关于为什么补的是第一位的值
           824    8247    8246    82    8249
补齐位数后  8248   8247    8246    8288  8249
找最大       3      4       5       1     2
最大数   82-8249-824-8247-8246
8249-824 > 824-8249
824-8247 > 8247-824
这样位数少的尽量排在前面，可以空出高位留给其他的数

```

### 代码

```cpp
class Solution {
public:
    //将nums中的每一个数补齐位数存入ves中，len记录所有数的位数y之和，count[]记录每个数的位数
    //不改变nums中的数和相对位置
    vector<int> fullfill(vector<int> nums,int& len,int count[]){
        vector<int> ves;
        int maxlen=0;        //最后补齐到的位数
        for(int i=0;i<nums.size();i++){
            int p=nums[i];    //每一个非负整数的位数
            if(p==0)
               count[i]=1;
            while(p){
                p/=10;
                count[i]++;
            }
            len+=count[i];
            maxlen=max(maxlen,count[i]);
        }
        for(int j=0;j<nums.size();j++){   //补齐位数
            int t=maxlen-count[j],q=0;    //t为nums[j]还需补的位数
            int w=nums[j];
            int r;
            int c=pow(10,count[j]-1); 
            if(w==0)
               r=0;
            else
               r=w/c;                     //r为非负整数的第一位的值
            while(q<t){                   //在需要补齐的地方都添为第一位的值
                w=w*10+r;
                q++;
            }
            ves.push_back(w);
        }
        return ves;                //ves中所有的数位数相同，且相对位置与nums[]中的一一对应
    }

    //找当前最大数，取出,加入结果
    int findbiggest(vector<int>& ves,vector<int> nums,int count[]){
        int max=ves[0],f=0; 
        for(int j=1;j<ves.size();j++){   //找最大数
            if(ves[j]>max){
                max=ves[j];
                f=j;                     //f记录最大数的位置，与nums[]中相对应
            }else if(ves[j]==max){
                int m=nums[j]*pow(10,count[f])+nums[f];
                int n=nums[f]*pow(10,count[j])+nums[j];
                f=m>n?j:f;
            }

        }    
        ves[f]=-1;
        return f;
    }

    string largestNumber(vector<int>& nums) {
        int flag=0;
        for(int i=0;i<nums.size();i++)    //如果全为 0 ，直接返回“0”
            if(nums[i]!=0)
               flag=1;
        if(flag==0){
            string r="0";
            return r;
        }
        int count[nums.size()]={0};
        int len=0;
        int t=0;
        vector<int> ves=fullfill(nums,len,count);  //补齐位数
        string str(len,'0');                       //构造字符串
        for(int i=0;i<ves.size();i++){
            int f=findbiggest(ves,nums,count);    
            int p=nums[f];                        //nums[f]为当前最大数
            if(p==0){                             //nums[f]==0 不用拆分，直接加入
                str[t++]='0';
                continue;
            }
            stack<int> s;                    //拆分整数，是从个位开始取的，需要用栈倒一下
            while(p){
                s.push(p%10);
                p/=10;
            }
            while(!s.empty()){
                str[t++]=s.top()+'0';        //整型转换为char
                s.pop();
            }
        }
        str[t]='\0';
        return str;
    }
};
```