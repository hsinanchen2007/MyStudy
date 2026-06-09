![image.png](https://pic.leetcode-cn.com/42ddb620139e80888cd4b6f99d97cfc3a69831f4d0b7afb5f4f1dbf66f2e3fdb-image.png)
第一次提交就过了百分之九十九！！开心！！虽然可能是蒙出来的！

主要思路是做了一个可进位的计数器
比如有四个数字'2579'的时候，计数器初始化为[0,0,0,0]
然后循环逐位加一遍历，计数器加一变为[0,0,0,1]
由于'9'有4个字符，计数器最大值为3，当计数器为[0,0,0,3]的时候加一进位，变成[0,0,1,0]

就是这样简单遍历的

`class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        #主要思路是做了一个计数器
        
        #处理空字符
        if not digits:
          return []
        #一个字典
        dic={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        #初始化计数器
        times=[0 for i in digits]
        #为计数器每一位设置最大值
        max_times=[len(dic[i]) for i in digits]
        #写第一个[0,0,0,0]的字符串
        out_str="".join([dic[digits[i]][times[i]] for i in range(len(digits))])
        out=[out_str]
        #循环写入，每次计数器加一
        while self.add_times(times,max_times):
            out_str="".join([dic[digits[i]][times[i]] for i in range(len(digits))])
            out.append(out_str)
        return out
    #一个进位计数器，每次加一，直到加满的时候返回false
    def add_times(self,times,max_times):
      for i in range(len(times)):
        #从末尾开始递归，进位的时候归本位为0
        if times[-i-1]+1>=max_times[-i-1]:
          times[-i-1]=0
        #不进位的时候本位加一返回true
        else:
          times[-i-1]+=1
          return True
      #全跑完也没true证明遍历完成进位溢出，返回false
      return False`