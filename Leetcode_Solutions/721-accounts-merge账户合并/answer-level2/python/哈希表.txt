# 解题思路
初始化集合account_name以及哈希表account_emails,same_names
遍历accounts,会遇到下列三种情况:
1). 如果是一个新账户:
```python
account_name.add(account[0])
account_emails[account[0]] = set(account[1:])
same_names[account[0]] = set()
same_names[account[0]].add(account[0])
```
2). 如果存在同名账户, 但是emails并没有重复：
```python
# 包含同名账户，那么检测一下同名账户中是否有email相同，若相同则合并这些账户
union_name_set = set()
# 新账户的命名问题
new_name = account[0] + '#' * len(same_names[account[0]])
while new_name in same_names[account[0]]:
    new_name += '#'
union_name_set.add(new_name)
for same_name in same_names[account[0]]:
    for email in account[1:]:
        if email in account_emails[same_name]:
            union_name_set.add(same_name)
            break
account_name.add(new_name)
account_emails[new_name] = set(account[1:])
same_names[account[0]].add(new_name)
```       
3). 若emails重复了,那么将所有包含重复email的账户取出,进行合并:
```python
union_list = list(union_name_set)
min_name = union_list[0]
for index in range(1,len(union_list)):
if len(union_list[index]) < len(min_name):
    min_name = union_list[index]
for name in union_list:
    if name != min_name:
        account_emails[min_name] = account_emails[min_name].union(account_emails[name])
        account_emails.pop(name)
        account_name.remove(name)
        same_names[account[0]].remove(name)
```       
# 代码
```python
class Solution:
    def accountsMerge(self, accounts: list) -> list:
        account_name = set()
        account_emails = {}
        same_names = {}
        for account in accounts:
            # 一个新账户
            if account[0] not in account_name:
                account_name.add(account[0])
                account_emails[account[0]] = set(account[1:])
                same_names[account[0]] = set()
                same_names[account[0]].add(account[0])
            else:
                # 包含同名账户，那么检测一下同名账户中是否有email相同，若相同则合并这些账户
                union_name_set = set()
                # 新账户的命名问题
                new_name = account[0] + '#' * len(same_names[account[0]])
                while new_name in same_names[account[0]]:
                    new_name += '#'
                union_name_set.add(new_name)
                for same_name in same_names[account[0]]:
                    for email in account[1:]:
                        if email in account_emails[same_name]:
                            union_name_set.add(same_name)
                            break
                # 无email与同名账户重复
                account_name.add(new_name)
                account_emails[new_name] = set(account[1:])
                same_names[account[0]].add(new_name)
                # 存在同名账户，这些账户全部都要合并
                if len(union_name_set) > 1:
                    union_list = list(union_name_set)
                    min_name = union_list[0]
                    for index in range(1,len(union_list)):
                        if len(union_list[index]) < len(min_name):
                            min_name = union_list[index]
                    for name in union_list:
                        if name != min_name:
                            account_emails[min_name] = account_emails[min_name].union(account_emails[name])
                            account_emails.pop(name)
                            account_name.remove(name)
                            same_names[account[0]].remove(name)
        result = []
        for name in account_name:
            temp = [name.strip('#')]
            temp += sorted(list(account_emails[name]))
            result.append(temp)
        return result
```
