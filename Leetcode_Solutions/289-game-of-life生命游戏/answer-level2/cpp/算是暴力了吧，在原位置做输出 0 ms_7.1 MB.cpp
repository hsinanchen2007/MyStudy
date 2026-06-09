4个条件，可以简化成

1.如果当前是活的，周围少于2个，多余3个的，下一波就会死

2.如果当前是死的，周围有2个或者3个的，下一波会活

3.其他的姿态保持不变

把（1）会死的设置为2，但是当前还是活的，所以值要大于0

把（2）会活过来的设置为-1，可当前还是死的，要小于0

if (board[y][x] == 0 && sum == 3) 
　　board[y][x] = -1;//可复活

else if (board[y][x] == 1 && (sum < 2 || sum > 3)) 
　　board[y][x] = 2;//要死了
设置sum表示周围8格的总数，只要大于0的变+1

            for (int index = 0; index < 8; ++index)
            {
                if (x + x_index[index] < 0 || x + x_index[index] >= x_size || y + y_index[index] < 0 || y + y_index[index] >= y_size) 
                    continue;
                if (board[y + y_index[index]][x + x_index[index]] > 0) 
                    sum++;
            }
最后再循环一遍，把2改为0，把-1改为1，其他的不变

    for (int y = 0; y < y_size; ++y)
    {
        for (int x = 0; x < x_size; ++x)
        {
            if (board[y][x] == -1) 
                board[y][x] = 1;
            else if (board[y][x] == 2) 
                board[y][x] = 0;
        }
    }
 

所有代码如下：
```
	if (board.size() == 0) return;

	int x_size = board[0].size();
	int y_size = board.size();
	int x_index[8] = { -1, 0, 1, -1,1, -1,0,1 };
	int y_index[8] = { -1,-1,-1, 0, 0, 1,1,1 };

	for (int y = 0; y < y_size; ++y)
	{
		for (int x = 0; x < x_size; ++x)
		{
			int sum(0);
			for (int index = 0; index < 8; ++index)
			{
				if (x + x_index[index] < 0 || x + x_index[index] >= x_size || y + y_index[index] < 0 || y + y_index[index] >= y_size) 
					continue;
				if (board[y + y_index[index]][x + x_index[index]] > 0) 
					sum++;
			}
			
			if (board[y][x] == 0 && sum == 3) 
				board[y][x] = -1;//可复活
			else if (board[y][x] == 1 && (sum < 2 || sum > 3)) 
				board[y][x] = 2;//要死了
			printf(" %d \n", board[y][x]);
		}
	}
	for (int y = 0; y < y_size; ++y)
	{
		for (int x = 0; x < x_size; ++x)
		{
			if (board[y][x] == -1) 
				board[y][x] = 1;
			else if (board[y][x] == 2) 
				board[y][x] = 0;
		}
	}
```
