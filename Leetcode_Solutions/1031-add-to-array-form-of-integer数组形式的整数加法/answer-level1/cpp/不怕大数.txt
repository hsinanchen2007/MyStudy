1. 将K存入数组
2. 两数组先相加相同长度部分并存入Vret数组，flag接收进位标志
3. 处理长数组剩余部分
4. 处理最后一位进位信息
5. ```
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if(A.empty()){
            return A;
        }
        vector<int> B;
        for(;K;K/=10){
            B.push_back(K%10);
        }
        reverse(B.begin(),B.end());
        //相加相同长度部分
        vector<int> &max = A.size()>B.size()?A:B;
        vector<int> &min = A.size()>B.size()?B:A;
        vector<int> Vret(max.size() + 1);
        int posMax = max.size() - 1;
        int posMin = min.size() - 1;
        int posRet = Vret.size() - 1;
        int flag = 0;
        for(;posMin >= 0;posMin--,posMax--,posRet--){
            Vret[posRet] = MyAdd(max[posMax],min[posMin],flag);
        }
        //多出权位进位
        for(;posMax >= 0;posMax--,posRet--){
            Vret[posRet] = MyAdd(max[posMax],0,flag);
        }
        if(1 == flag){
            Vret[0] = 1;
            return Vret;
        }
        return vector<int>(++Vret.begin(),Vret.end());
    }
    int MyAdd(int x,int y,int &flag){
        int ret = x + y + flag;
        if(ret > 9)
            flag =1;
        else
            flag =0;
            return ret%10;
    }
};
```
