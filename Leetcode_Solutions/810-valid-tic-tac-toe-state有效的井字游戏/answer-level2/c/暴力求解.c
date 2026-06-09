		bool validTicTacToe(char ** board, int boardSize){
			int i, j;
			int xSum = 0, oSum = 0;
			int xSame = 0, oSame = 0;    
			for (i = 0; i < boardSize; i++) {
				int xrowCnt = 0, orowCnt = 0;
				int xSlantCnt = 0, oSlantCnt = 0;
				int xlineCnt = 0, olineCnt = 0;       
				for (j = 0; j < boardSize; j++) {
					if (board[i][j] == 'X') {
						xlineCnt++;
						xSum++;
					} else if (board[i][j] == 'O') {
						olineCnt++;
						oSum++;
					}
					if (board[j][i] == 'X') {
						xrowCnt++;
					} else if (board[j][i] == 'O') {
						orowCnt++;
					}
				}
				if (xlineCnt == 3) {
					xSame++;
				}
				if (xrowCnt == 3) {
					xSame++;
					xrowCnt = 0;
				}
				if (olineCnt == 3) {
					oSame++;
				}
				if (orowCnt == 3) {
					oSame++;
					orowCnt = 0;
				}
			}
		
			if (xSum < oSum || xSum > oSum + 1) {
				return false;
			}
		
			int xSlantCnt = 0, oSlantCnt = 0;
			if (board[2][0] == 'X') {
				xSlantCnt++;
			} else if (board[2][0] == 'O') {
				oSlantCnt++;
			}
			if (board[1][1] == 'X') {
				xSlantCnt++;
			} else if (board[1][1] == 'O') {
				oSlantCnt++;
			}
			if (board[0][2] == 'X') {
				xSlantCnt++;
			} else if (board[0][2] == 'O') {
				oSlantCnt++;
			}
			if (xSlantCnt == 3) {
				xSame++;
			}
			if (oSlantCnt == 3) {
				oSame++;
			}
			oSlantCnt = 0;
			xSlantCnt = 0;
			for (i = 0; i < boardSize; i++) {
				if (board[i][i] == 'X') {
					xSlantCnt++;
				} else if (board[i][i] == 'O') {
					oSlantCnt++;
				}
			}
			if (xSlantCnt == 3) {
				xSame++;
			}
			if (oSlantCnt == 3) {
				oSame++;
			}
			if (xSame == 1 && oSame == 1) {
				return false;
			}
		
			if (xSame == 1 && xSum == oSum) {
				return false;
			}
		
			if (oSame == 1 && xSame == 0 && xSum > oSum) {
				return false;
			}
		
			return true;
		}