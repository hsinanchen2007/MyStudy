```
class Solution:
    def wordPatternMatch(self, pattern: str, string: str) -> bool:
        def helper(pattern, string, left_pattern, left_str, map_relation,
                   map_relation_inverse):

            # 判断是否访问完了pattern
            if left_pattern == len(pattern):
                if left_str == len(string):
                    return True
                else:
                    return False

            # 判断历史上是否见过这个pattern
            if pattern[left_pattern] in map_relation:
                length = len(map_relation[pattern[left_pattern]])
                if string[left_str:left_str +
                          length] != map_relation[pattern[left_pattern]]:
                    return False
                else:
                    return helper(pattern, string, left_pattern + 1,
                                  left_str + length, map_relation,
                                  map_relation_inverse)

            # 历史上没有见过，就从当前位置开始往后尝试
            for i in range(left_str, len(string)):
                may_string = string[left_str:i + 1]
                map_relation[pattern[left_pattern]] = may_string
                if may_string in map_relation_inverse:
                    map_relation.pop(pattern[left_pattern])
                    continue
                map_relation_inverse.add(may_string)
                # 增加这个pattern之后不会产生矛盾，就继续下一层
                if helper(pattern, string, left_pattern + 1, i + 1,
                          map_relation, map_relation_inverse):
                    return True
                else:
                    # 下一层不可以的话，回溯上一个
                    map_relation.pop(pattern[left_pattern])
                    map_relation_inverse.remove(may_string)
                    continue
            return False

        left_pattern = 0
        left_str = 0
        map_relation = {}
        map_relation_inverse = set()
        if len(pattern) == 0 and len(string) == 0:
            return True
        if len(pattern) == 0 or len(string) == 0:
            return False
        return helper(pattern, string, left_pattern, left_str, map_relation,
                      map_relation_inverse)

```
