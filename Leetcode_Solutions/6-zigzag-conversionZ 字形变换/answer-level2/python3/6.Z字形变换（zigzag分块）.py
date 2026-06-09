```Python
# 可是使用字符串索引(0, 1, 2, ..., len(s)-1)，画出zigzag（len(s)和numRows自己指定一个就好），
# 分别计算出zigzag竖线和斜线上元素对应于字符串s中的索引。
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        slen = len(s)
		# 如果字符串长度小于行数，或行数为1，字符串原样返回
        if slen <= numRows or numRows == 1:
            return s
        else:
			# 将zigzag分成若干块 block
			# 每一块中元素的个数
            numElemPerBlock = 2 * numRows - 2
			# 整个zigzag中的block数
            numBlocks = slen//numElemPerBlock if (slen%numElemPerBlock)==0 else slen//numElemPerBlock+1
			# 初始化zigzag字符串为空
            zigzag = ''
			# 使用一个双重循环读取zigzag字符串
			# 先按行，再按块
            for irow in range(numRows):
                for iblock in range(numBlocks):
                    idx1 = irow + iblock * numElemPerBlock	# zigzag竖线上元素的索引
                    idx2 = irow + iblock * numElemPerBlock + 2 * (numRows -1 - irow)	# zigzag斜线上元素的索引
                    
					# 每一个block中，第一行和最后一行只有一个元素，即竖线元素
					# 注意索引不能超过字符串的最大索引
                    if irow == 0 or irow == numRows-1:	
                        if idx1 < slen:
                            zigzag += s[idx1]
                    else:	# 其他行有两个元素，竖线元素和斜线元素
                        if idx1 < slen:
                            zigzag += s[idx1] 
                        if idx2 < slen:
                            zigzag += s[idx2]
            return zigzag