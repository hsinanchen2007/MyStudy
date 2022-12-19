解题思路：
1、遍历所有节点
2、检查周围节点通过该节点到达门的距离会不会更短，若会则更新节点值，并递归判断修改后的节点值。
ps：当节点值为-1或INT_MAX时无需判断直接返回


```
void check(int** rooms, int roomsSize, int roomsColSize , int x, int y)
{
    //检测通过该节点能否使四周节点到门的距离缩短，若能则修改节点值，并判断修改后节点能否使四周节点值改变
    if(rooms[x][y] == INT_MAX ||rooms[x][y] == -1)return;
    int num = rooms[x][y] +1;
    if(x-1 >=0 && rooms[x-1][y]!= -1 && rooms[x-1][y] > num)
    {
        rooms[x-1][y] = num;
        check(rooms,roomsSize,roomsColSize,x-1,y);
    }
    if(x+1 < roomsSize && rooms[x+1][y]!= -1 && rooms[x+1][y] > num)
    {
        rooms[x+1][y] = num;
        
        check(rooms,roomsSize,roomsColSize,x+1,y);
    }
    if(y-1 >=0 && rooms[x][y-1]!= -1 && rooms[x][y-1] > num)
    {
        rooms[x][y-1] = num;
        check(rooms,roomsSize,roomsColSize,x,y-1);
    }
    if(y+1 < roomsColSize && rooms[x][y+1]!= -1 && rooms[x][y+1] > num)
    {
        rooms[x][y+1] = num;
        check(rooms,roomsSize,roomsColSize,x,y+1);
    }
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){    
    //遍历每个节点
    for(int i=0;i<roomsSize;i++)
    {
        for(int j=0;j<*roomsColSize;j++)
        {
            //检测通过该节点能否使四周节点到门的距离缩短，若能则修改节点值，并判断修改后节点能否使四周节点值改变
            check(rooms,roomsSize,*roomsColSize,i,j);
        }
    }
    
}
```
