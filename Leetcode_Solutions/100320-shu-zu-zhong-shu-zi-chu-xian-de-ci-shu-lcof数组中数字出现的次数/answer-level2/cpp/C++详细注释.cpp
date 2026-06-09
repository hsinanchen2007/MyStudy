class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp=0;
        int i;
        int len = nums.size();
        for(i=0; i<len; ++i){
            temp ^= nums[i];
        } 
        cout<<"temp="<<temp<<endl;
        // 此时temp为1的那一位是出现一次数字不同的位，
        // 不过应该注意temp中可能有多位为1,不利于判断
        // 选择最低位为1的那个temp
        // 其他的出现两次的数字按这位为1或者0分成两组
        int n=1;
        if(n&temp);
        else{
            for(i=0; i<32; ++i){
                n<<=1;   // 不要写成n<<=i;
                if(n&temp)  // 不要用n=n&temp再判断n，因为n的数值被改变了，可以用辅助变量
                    break;
            }
        }
        cout<<"n="<<n<<endl;
        // 此时的n就记录了那一位
        temp = 0;
        int temp1 = 0;
        for(i=0; i<len; ++i){
            cout<<nums[i];
            int t = nums[i]&n;
            if(t!=0) // i的那一位是0，那么就分为第0组
                temp ^= nums[i];
            else
                temp1 ^= nums[i];
        }
        vector<int> result;
        cout<<"temp="<<temp;
        cout<<"temp1="<<temp1;
        result.push_back(temp);
        result.push_back(temp1);
        return result;
    }
};