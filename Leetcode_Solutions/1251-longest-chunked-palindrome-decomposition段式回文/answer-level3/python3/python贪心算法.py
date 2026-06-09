#从两端往中间遍历，如果字符串一致则分割，结果+2；否则保留当前累加当前字符；最后判断一下会不会有多余的字符串，有的话结果+1
class Solution:
    def longestDecomposition(self, text):
        length = len(text)
        if(length==0 or length==1):
            return 1
        left, right, num, left_l,right_r = 0,length-1,0,"",""
        while(left<right):
            left_l+=text[left]
            right_r = text[right]+right_r
            if(left_l == right_r):
                num+=2
                left+=1
                right-=1
                length-=2*len(left_l)
                left_l=''
                right_r=''
            else:
                left+=1
                right-=1
        return num+1 if(length>0) else num