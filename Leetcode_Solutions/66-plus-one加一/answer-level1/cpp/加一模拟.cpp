class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1,carry=1;//carry初始为1表示原数加1
        for(int i=n;i>=0&&carry==1;i--){//没有进位结束操作
            int tmp=carry;//tmp存储carry，防止carry更新覆盖
            carry=(carry+digits[i])/10;
            digits[i]=(tmp+digits[i])%10; 
        }
        if(carry==1)digits.insert(digits.begin(),carry);//处理最高位有进位
        return digits;
    }
};