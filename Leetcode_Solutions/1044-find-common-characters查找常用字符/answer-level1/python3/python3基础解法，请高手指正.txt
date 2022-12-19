class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        output = ''
        for i in A[0]:       #以第一个单词作为基准跟后面所有单词比较
            for j in range(1, len(A)):  
            #如果A[0]中的某一个字母不在后面的某一个单词中，检测A[0]中的下一个字母    
                if i not in A[j]:  
                    break
            #如果某一个字母在后面的单词中都有，那么在每个单词中都删除这个字母一次    
                else:   
                    A[j] = A[j].replace(i, '', 1)
            else:     #如果循环完成没有跳出，则在输出列表中加入这个字母
                output += i
        return ''.join(output)