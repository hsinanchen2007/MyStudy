异或运算满足以下定律：（离散数学有详解）

交换律：a ^ b ^ c <=> a ^ c ^ b

 任何数与0异或 0 ^ n = n

相同的数异或为0 n ^ n => 0

根据三条定律，用0与数组中所有元素分别异或，最后会得到没有相同的那个数。


    int singleNumber(vector<int>& nums) {
        
        int result = 0;
        for(int e : nums)
        {
            result ^=e;
        }
        return result;
    }
};
看了好多大神的解，没明白，找书整 明白了。。。。
