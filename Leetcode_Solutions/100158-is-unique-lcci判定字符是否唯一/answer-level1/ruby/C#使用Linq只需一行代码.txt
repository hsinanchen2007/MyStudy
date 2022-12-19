灵感来自于脚本语言，强大的 .Net 使得 C# 也可以像脚本语言一简便
```
public class Solution {
    public bool IsUnique(string astr) {
      return astr.Distinct().Count() == astr.Length;
    }
}
```
类比 Ruby
```
# @param {String} astr
# @return {Boolean}
def is_unique(astr)
  return astr.chars.uniq.length == astr.length
end
```
