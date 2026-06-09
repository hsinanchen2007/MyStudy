#本题没有想到回溯法，只是通过找规律求解
#该题规律是格雷编码每增加一个位数(当前位n位），就相当于对n-1位结果对应的数组做镜像处理，
#并将镜像处理得到的列表加到原来列表之后，且对后后一半列表再加上pow(2,n-1)
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        lists = [0,1]
        ans = []
        #共进行n-1轮操作
        for i in range(1, n):
            #记录上一轮得到结果的长度
            len_before = len(lists)
            temp = list(reversed(lists))
            lists = lists + temp
            for j in range(len_before, 2*len_before):
                lists[j] = pow(2, i)+ lists[j]
        return lists