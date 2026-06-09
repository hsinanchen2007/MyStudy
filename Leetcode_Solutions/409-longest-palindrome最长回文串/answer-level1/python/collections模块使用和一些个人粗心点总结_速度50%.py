### 解题思路
（1）文字思路
最大回文数，即为对称数。
如果元素是成对出现，那么最简单的排序是一头一尾各放一个
如果元素出现次数多于一对且为偶数（4,6,8...），那么可拆分为2对2..，然后回到上述排列方式进行排列
如果元素出现奇数次（大于1，即为3,5,7...），可拆分为2+1,4+1,...，按照上述方式进行排列
如果元素出现次数为1，则放在一边，最后回文数总长度计入1个长度即可
（2）代码思路
首先需要模块方法对字符串进行元素个数的计数，此时用到collections模块比较方便，模块下的Counter()方法可以实现这个功能，并以键对形式返回字典形式。collections.Counter()方法可参考https://blog.csdn.net/weixin_42598585/article/details/86562965?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
其次，即为对文字思路的读取，用到一次for循环和两次 if-else
其出现的问题贴在注释中了
值得一提的是，关于元素出现奇数次，如何盘对回文数长度是否加1，需要着重思考:
       # if total_num % 2 == 1:
       #    return length_str + 1
       # else:
       #    return length_str
如果是"abcccc",那么total_num为偶数，那么就会造成判断错误，回文数不会计入一个奇数元素
因此，需要用到left_num（是所有奇数元素出现次数的总和，只要存有奇数元素，则left_num就会大于0）
       

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        import collections 
        #collections针对set，list，dict，str等数组集合，下属很多方法作用于这些数组
        dict_ = collections.Counter(s)
        #Counter()方法一定是大写C，对s个元素进行计数，返回值为一个字典，如s="abc",dict_={"a":1,"b":1,"c":1}
        num = dict_.values()
        #num是一个包含s中元素出现次数的列表
        length_str = 0
        # total_num = 0
        left_num = 0
        for i in num:
            # total_num += i
            if i%2 ==0:
                length_str += i
            else:
                length_str += i - 1
                #如果元素出现3，5,7...次数，应把偶数部分拎出使用
                left_num += i
                #是所有奇数元素出现次数的总和，只要存有奇数元素，则left_num就会大于0
        if left_num > 0:
            return length_str + 1
        else:
            return length_str
       # if total_num % 2 == 1:
       #    return length_str + 1
       # 选择一个奇数元素放在中间，则增加一单位长度，且不影响对称
       # else:
       #    return length_str
       





```