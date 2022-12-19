```
class Solution:
    def findStrobogrammatic(self, n: int):
        if n == 0:
            return []
        if n==1:
            return ["0","1","8"]
        lookup = {
            "0": "0",
            "1": "1",
            "6": "9",
            "8": "8",
            "9": "6"
        }
        lookup_center={
            "0":"0",
            "1":"1",
            "8":"8"
        }
        rs = []
        if n % 2 == 0:
            list1 = []
            first_str = ""
            second_str = ""
            list1.append((first_str, second_str))
            while list1:
                first_str, second_str = list1.pop(0)
                if first_str.__len__() > n // 2:
                    break
                if first_str.__len__() == n // 2:
                    tmp_str=first_str + second_str
                    if tmp_str.__len__()>=2 and tmp_str[0]=="0":
                        continue
                    rs.append(first_str + second_str)
                for key in lookup:
                    list1.append((first_str + key, lookup[key] + second_str))

        if n % 2 == 1:
            list1 = []
            first_str = ""
            second_str = ""
            list1.append((first_str, second_str))

            while list1:
                first_str, second_str = list1.pop(0)
                if first_str.__len__() > n // 2:
                    break
                if first_str.__len__() == n // 2:
                    for key in lookup_center:
                        tmp_str = first_str +key+ second_str
                        if tmp_str.__len__() >= 2 and tmp_str[0] == "0":
                            continue
                        rs.append(first_str + key + second_str)
                for key in lookup:
                    list1.append((first_str + key, lookup[key] + second_str))
        return rs
```