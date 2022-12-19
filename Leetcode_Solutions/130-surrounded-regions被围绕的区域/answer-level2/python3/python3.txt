	if not board:
		return
	row, col = len(board), len(board[0])
	res = []
	for j in range(col):
		if board[0][j] == 'O':
			board[0][j] = '1'
			res.append([0, j])
		if board[row - 1][j] == 'O':
			board[row - 1][j] = '1'
			res.append([row - 1, j])
	for i in range(1, row - 1):
		if board[i][0] == 'O':
			board[i][0] = '1'
			res.append([i, 0])
		if board[i][col - 1] == 'O':
			board[i][col - 1] = '1'
			res.append([i, col - 1])
	while res:
		i, j = res.pop(0)
		left, right, up, down = j - 1, j + 1, i - 1, i + 1
		if left >= 0 and board[i][left] == 'O':
			board[i][left] = '1'
			res.append([i, left])
		if right < col and board[i][right] == 'O':
			board[i][right] = '1'
			res.append([i, right])
		if up >= 0 and board[up][j] == 'O':
			board[up][j] = '1'
			res.append([up, j])
		if down < row and board[down][j] == 'O':
			board[down][j] = '1'
			res.append([down, j])
	for i in range(row):
		for j in range(col):
			if board[i][j] == '1':
				board[i][j] = 'O'
			else:
				board[i][j] = 'X'