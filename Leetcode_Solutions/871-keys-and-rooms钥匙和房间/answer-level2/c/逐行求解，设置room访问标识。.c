### 解题思路
递归方法求解。

### 代码

```c

void dfs(int** rooms,int room, int roomsSize, int* roomsColSize, int *visit){

    if(visit[room])
    {
        return;
    }
    visit[room] = 1;

	for(int key = 0; key < roomsColSize[room]; key++)
	{
		int tmpR = rooms[room][key];

		dfs(rooms,tmpR, roomsSize, roomsColSize, visit);
	}


}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){

  
  int visit[roomsSize];
  for(int i = 0; i < roomsSize; i++)
  {
       visit[i] = 0;
  }
  int count = 0;
  visit[0] = 1;
  for(int i = 0; i < roomsColSize[0]; i++) {
  
      int r = rooms[0][i];

      dfs(rooms,r, roomsSize, roomsColSize, visit);

  }
  for(int i = 0 ; i < roomsSize; i++ )
  {
     if(visit[i] == 1)
	 {
	    count++;
	 }
  }
  if(roomsSize != count) {
      return false;
  }
  return true;

}
```