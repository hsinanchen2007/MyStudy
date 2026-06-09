**时间:** O(n)
**空间:** O(1)

**三步解决问题**
1. 生成格雷码，与[第89题](https://leetcode-cn.com/problems/gray-code/)相同
2. 找到start的位置
3. 旋转数组，与[第189题](https://leetcode-cn.com/problems/rotate-array/)相同

**如何生成格雷码？**
基于格雷码是反射码的事实，利用如下规则：
- 1位格雷码有两个码字
- (n+1)位格雷码中的前2^n个码字等于n位格雷码的码字，按顺序书写，加前缀0
- (n+1)位格雷码中的后2^n个码字等于n位格雷码的码字，按逆序书写，加前缀1
- n+1位格雷码的集合 = n位格雷码集合(顺序)加前缀0 + n位格雷码集合(逆序)加前缀1

例如： 生成一个3位格雷码的过程
- 初始: 0,1
- 复制前一行，添加前缀0: 00, 01
逆序复制前一行，添加前缀1: 11, 10
于是得到 00, 01, 11, 10
- 复制前一行，添加前缀0: 000, 001, 011, 010
逆序复制前一行，添加前缀1: 110, 111, 101, 100
于是得到 000, 001, 011, 010, 110, 111, 101, 100


```C++ []
vector<int> circularPermutation(int n, int start) {
    vector<int> res = {0,1};
    for(int i = 2;i <= n;i++){
        for(int j = res.size()-1;j >= 0;j--){
            res.push_back(res[j] + (1 << (i-1)));
        }
    }
		
    int l = 0,r = res.size()-1;
    while(l <= r){
        if(res[l] == start || res[r] == start) break;
        l++,r--;
    }
		
    if(res[l] == start){
        reverse(res.begin(),res.end());
        reverse(res.begin(),res.end()-l);
        reverse(res.end()-l,res.end());
    }else{
        reverse(res.begin(),res.end());
        reverse(res.begin(),res.begin()+l+1);
        reverse(res.begin()+l+1,res.end());
    }
    return res;
}
