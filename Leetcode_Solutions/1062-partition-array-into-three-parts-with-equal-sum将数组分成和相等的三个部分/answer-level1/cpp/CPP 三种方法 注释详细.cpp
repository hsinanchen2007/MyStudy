// 【通过】自己写的一种方法，不是很严谨，数据刚好相等就翻车了，本以为很简单，结果翻车了好几次，越改越复杂，就这样吧。
// ```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<float>B (A.size(),-1);                           //创建一个B数组保存遍历至此的平均数
        int ans = 0;
        for(int i=0;i<A.size();i++){
            ans+=A[i];
            B[i]=(float)ans/3;
        }
        if((int)B[B.size()-1]!=B[B.size()-1])                   //如果B的最后一个平均数不是整数说明不能被整除
            return false;
        float num1=B[B.size()-1]/3,num2=B[B.size()-1]/3*2;      //num1和num2就是要找的前两个平均数
        for(int i=0;i<B.size();i++){
            if(B[i]==num1){                                     //num1=总平均数的1/3一定出现在num2前面
                num1=-1;                                        //找到了标记为-1（不严谨）
                continue;
            }
            if(num1==-1&&B[i]==num2&&i<B.size()-1)num2=-1;      //确保找到了num1并且num2后面还有空间
        }
        return num1==num2;
    }
};
// ```
// 【通过】比较简单的一种方法
// ```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int ans=0,target=0,sum=0,success=0;     //ans总和 target目标数 sum累加器 success达到目标数的次数
        for(int x:A)                            //首先计算总和
            ans+=x;
        if(ans%3!=0)                            //如果不能被3整除返回false
            return false;
        target=ans/3;                           //目标数=总和/3
        for(int x:A){
            sum+=x;
            if(sum==target){                    //达到目标数清零累加器 成功次数+1
                sum=0;
                success++;
            }
        }
        if(sum==0&&success>2)                   //最后累加器为0，成功次数至少3次则成功
            return true;
        return false;
    }
};
// ```
// 【超时】下面是一开始写的笨方法，超时🥺
// ```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s1=0,s2=0,s3=0;
        bool succ=false;
        for(int i=0;i<A.size()-2;i++){
            for(int j=0;j<=i;j++)
                s1+=A[j];
            for(int j=i+1;j<A.size()-1;j++){
                s2+=A[j];
                if(s2==s1){
                    for(int k=j+1;k<A.size();k++)
                        s3+=A[k];
                    if(s3==s2)
                        succ=true;
                }
            }
            if(succ==true){
                break;
            }else{
                s1=s2=s3=0;
            }
        }
        return succ;
    }
};
// ```
