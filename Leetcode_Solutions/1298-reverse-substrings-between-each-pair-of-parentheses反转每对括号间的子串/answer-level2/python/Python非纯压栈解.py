考虑到会进行多次反转，可以不用直接操作数组，通过计算的方法一次成型，那么直接通过两遍遍历分别记录括号的情况然后根据括号的情况移动数字到最终位置，考虑到括号的包含关系，因此需要进行排序和比较括号长度，短的在内，然后在第二遍遍历时，遇到左括号则加入待运算列表，遇到右括号则移除，剩余情况直接计算对应位置，时间复杂度为O(n)，数组长度越长，括号越多，效率优势越显著
在100w长度，1w括号的规模上，速度（第一行）超过纯栈操作（第二行）和自带函数[::-1]（第三行）的效率
![1190-100w-1w.png](https://pic.leetcode-cn.com/ab9c3a17efb5a18da1fd89eaf1e267e53548b91981d18649b697cd9e0e127e67-1190-100w-1w.png)
100w长度，10w括号
![1190-100w-10w.png](https://pic.leetcode-cn.com/f30cff894dc738a268ccb990b1d8bf5961bfef6bd155fbe8ed8655086086a1f0-1190-100w-10w.png)
1000w长度，10w括号
![1190-1000w-10w.png](https://pic.leetcode-cn.com/c4fe9f7d7c8b207ae0b43a22d14188fe0120b59b0e0ba0551843fa49372655b0-1190-1000w-10w.png)


```
    string_list = []
    cnt_list = 1
    bracket_left = []
    bracket_list = []
    bracket_list_now = []

    for i in range(0, len(s)):
        if '(' == s[i]:
            bracket_left.append(cnt_list)
        elif ')' == s[i]:
            loc_left = bracket_left.pop()
            loc_right = cnt_list - 1
            if loc_left < loc_right:
                bracket_list.append([loc_left, loc_right, loc_right - loc_left])
        else:
            string_list.append(s[i])
            cnt_list += 1
    bracket_list = sorted(bracket_list, key=lambda x: (-x[0], x[2]))
    len_bracket_list = len(bracket_list)
    calc_base = 0
    # print(bracket_list)
    # print(string_list)

    positive = 1
    ans = [0 for i in range(len(string_list))]

    for i in range(0, len(string_list)):
        if bracket_list:
            while True:
                if bracket_list and i + 1 == bracket_list[len_bracket_list - 1][0]:
                    if positive:
                        calc_base += bracket_list[len_bracket_list - 1][0] + bracket_list[len_bracket_list - 1][1]
                        positive = 1 - positive
                    else:
                        calc_base -= bracket_list[len_bracket_list - 1][0] + bracket_list[len_bracket_list - 1][1]
                        positive = 1 - positive
                    bracket_list_now.append(bracket_list[len_bracket_list - 1])
                    bracket_list.pop()
                    len_bracket_list -= 1
                else:
                    break

        if positive:
            ans[calc_base + (i + 1) - 1] = string_list[i]
        else:
            ans[calc_base - (i + 1) - 1] = string_list[i]

        if bracket_list_now:
            len_bracket_list_now = len(bracket_list_now)
            j = len_bracket_list_now - 1
            while j >= 0:
                if i + 1 == bracket_list_now[j][1]:
                    temp = bracket_list_now.pop(j)
                    if positive:
                        calc_base += temp[0] + temp[1]
                        positive = 1 - positive
                    else:
                        calc_base -= temp[0] + temp[1]
                        positive = 1 - positive
                    len_bracket_list_now -= 1
                    j -= 1
                else:
                    break
    # return ans
    return "".join(ans)
```
