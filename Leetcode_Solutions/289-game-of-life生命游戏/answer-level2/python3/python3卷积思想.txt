第一步增加数组的行列数，防止边界溢出，有点像卷积的padding

def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        import numpy as np
        cell_array = np.array(board)
        h,w = cell_array.shape
        h_stack = np.zeros((h,1))
        w_stack = np.zeros((1,w+2))
        cell_array = np.column_stack((cell_array,h_stack))
        cell_array = np.column_stack((h_stack,cell_array))
        cell_array = np.row_stack((w_stack,cell_array))
        cell_array = np.row_stack((cell_array,w_stack))

        for i in range(h):
            for j in range(w):
                live_num = sum(sum(cell_array[i:i+3,j:j+3]))-cell_array[i+1,j+1]
                if live_num<2 or live_num>3:
                    board[i][j] = 0   ##少于2个或大于3个，dead
                elif live_num == 3 and board[i][j]==0:
                    board[i][j] = 1  ##3个，relive