
【题目分析】
本次属于单纯的组合问题，要求输出的是所有的组合，且没有输出次序限制，则不管什么解都需要求出所有的组合，都是变形的暴力解。
本方法的优化在于不存在重复求解，单纯进行组合放进结果，空间复杂度为结果大小，时间复杂度为O(3^N), N为digits的长度。
时间0ms,空间6.5ms,C++两方面均100%

只是单纯的暴力组合（从第一个string中依次挑选与下一个string依次组合），方法较为简单，只是存在编程技巧。
代码已详细注释。
```cpp
vector<string> letterCombinations(string digits) 
{
    vector<string> ret; //返回结果
    if(digits.empty())
    {
        return ret;
    };
    //映射原始数字为对应的string eg:2->"abc"
    auto cal_s = [](int i) ->string
    {
        switch(i)
        {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
            default: return "";
        };
    };
    //对s进行append每个字符的扩展
    //eg s="a", append="def"
    //1. 改"a"为"ad",,直接修改，避免删除"a"，再添加"ad"的时间损失
    //2.后面依次添加 "ae","af"
    //时间复杂度1.:O(append.length())，最大为O(4),即O(1)
    auto extern_s = [&](string& s, string append) 
    {
        string s_bak = s;
        s += append[0];
        for(int i =1; i< append.length(); i++)
        {
            ret.push_back(s_bak + append[i]);
        };
    };
    //因为采用的是直接暴力添加方法，ret先添加空"",否则循环进不去，""最后会被修改
    ret.push_back("");
    //遍历digits
    for(auto nc: digits)
    {
        //Warning: 下两行不可直接写为： for(int i =0; i< ret.size(); i++); 
        //因为每次进循环后ret都会被修改，方法只是在现有的基础上添加
        size_t ret_size = ret.size();
        for(int i =0; i< ret_size; i++) //时间复杂度2.因为每次进循环ret的size都会变化，1,3,3^2,3^3..等比数列
        {
            //对当前生成的组合每个进行新的cal_s(nc-'0')的组合添加到后面，原来的会被修改
            extern_s(ret[i], cal_s(nc-'0'));  //O(1)
        }
    };
    return ret;
};
```
时间复杂度：（时间复杂度2） * (时间复杂度1）
时间复杂度2：for循环标记的那行代码，等比数列求和 (3^n - 1) / 2 ,即O(3^n /2)
时间负责度1： O(4)，即O(1)
总时间复杂度: O(3^n)
空间复杂度：结果长度，任何算法不可避免