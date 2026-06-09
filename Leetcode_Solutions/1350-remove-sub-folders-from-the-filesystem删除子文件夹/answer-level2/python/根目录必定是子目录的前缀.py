对 `folder` 按字典序排序，如果目录 `x` 在 `folder` 中存在根目录，那么这个根目录必定在 `x` 之前。

1. 将第一个目录作为根目录
2. 从第二个目录开始遍历，判断 `folder[i]` 是否以当前根目录为前缀：
    - 是：`folder[i]` 是子目录，跳过该目录，不记录到结果中
    - 否：将当前根目录更新为 `folder[i]`

ps: 作为根目录时结尾加个 `/`，不然 `"/a/b/c"` 就是 `"/a/b/ca"` 的前缀了。

#### 实现

```python
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # 排序
        folder.sort()
        res = [folder[0]]
        # 将第一个目录设为当前根目录
        root = folder[0] + "/"
        
        for i in range(1, len(folder)):
            # 是否以 root 为前缀
            if not folder[i].startswith(root):
                # 不是子目录
                root = folder[i] + "/" # 更新根目录
                res.append(folder[i])
                
        return res
```