```
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        my_dict = {}
        for i, v in enumerate(s):
            if not my_dict.has_key(v): #如果v没有映射任何字母
                if t[i] not in my_dict.values(): #同时t[i]还没有被映射过
                    my_dict[v] = t[i] #那么v映射t[i]
                else: #如果t[i]已经被映射过(此时一定不是v映射的它)，那么显然v不可能再映射它
                    return False           
            else:       
                if my_dict[v] != t[i]: #如果v映射的字母不是t[i]
                    return False
        return True
```
