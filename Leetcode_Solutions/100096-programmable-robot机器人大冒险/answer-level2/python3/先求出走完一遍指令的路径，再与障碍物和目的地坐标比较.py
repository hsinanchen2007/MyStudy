每次走的是重复的路径，把第一次走的每一步坐标放入列表中。
之后每一步都是在原来的基础上走的循环，若减去原来的基础，这一坐标就应该在已存的列表中。

[o[0]-min(o[0]//sx,o[1]//sy)*sx,o[1]-min(o[0]//sx,o[1]//sy)*sy]障碍物坐标
[x-min(x//sx,y//sy)*sx,y-min(x//sx,y//sy)*sy]目的地坐标

```
        i=j=0
        list01=[[0,0]]
        for c in range(len(command)):
            if command[c]=='U':
                j+=1
            else:
                i+=1
            list01.append([i,j])
        sx=list01[-1][0]
        sy=list01[-1][1]
        for o in obstacles:
            if o[0]<=x and o[1]<=y:
                if [o[0]-min(o[0]//sx,o[1]//sy)*sx,o[1]-min(o[0]//sx,o[1]//sy)*sy] in list01:
                    return False
        if [x-min(x//sx,y//sy)*sx,y-min(x//sx,y//sy)*sy] in list01:
            return True
        else:
            return False

```
