```
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        # 40 ms
        # 12.7 MB
        if path == "":
            return "/"
        path = path.replace("//", "/")
        path_list = path.split("/")
        ans_list = ["" for _ in range(0, len(path_list))]
        ans_list[0] = "/"
        ans_index = 1
        for i in range(0, len(path_list)):
            if path_list[i] == "..":
                ans_index -= 1
                if ans_index < 1:
                    ans_index = 1
            elif path_list[i] == "." or path_list[i] == "":
                continue
            else:
                ans_list[ans_index] = path_list[i]
                ans_index += 1
        ans_str = ""
        for i in range(0, ans_index):
            if ans_list[i] != "" and ans_list[i] != "/":
                ans_str += "/"+ans_list[i]
        ans_str = "/" if ans_str == "" else ans_str
        return ans_str
```
