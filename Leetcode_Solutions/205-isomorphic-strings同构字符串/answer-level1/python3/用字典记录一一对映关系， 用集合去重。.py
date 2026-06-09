    class Solution:
        def isIsomorphic(self, s: str, t: str) -> bool:
            
            record = {}
            # 先确认单个字符对单个字符的一一映射的关系
            for i in range(len(s)):
                if s[i] not in record:
                    record[s[i]] = t[i]
                    
                elif record[s[i]] != t[i]:
                    return False
            
            # 再确定是否有多个不同的字符映射到同一个字符上
            if len(set(record.values())) != len(record.values()):
                return False
            
            return True