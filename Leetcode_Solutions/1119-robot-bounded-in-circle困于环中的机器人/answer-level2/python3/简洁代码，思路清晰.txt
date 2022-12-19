```
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        posO,pos = (0,0),[0,0]
        # 0-3的数字依次代表上-右-下-左
        dircO=dirc=0
        for i in instructions:
            if i=='G':
                mg={0: [0,1], 2: [0,-1], 3: [-1,0], 1: [1,0]}
                pos[0]+=mg[dirc][0]
                pos[1]+=mg[dirc][1]
            # 新旧方向产生新的方向
            elif i=='R':
                # mr={'U': 'R', 'D': 'L', 'L': 'U', 'R': 'D'}
                dirc=(dirc+1)%4
            elif i=='L':
                # ml={'U': 'L', 'D': 'R', 'L': 'D', 'R': 'U'}
                dirc=(dirc+3)%4
        # 方向改变（绕一个时针方向总会绕回来）或者位置未变（确定能回来）
        return dirc!=dircO or pos==list(posO)
```
