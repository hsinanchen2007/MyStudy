先横着数，再竖着数，再斜着数，不动脑子，但没什么不好意思的，简单实用

    public int longestLine(int[][] M) {
        int longest = 0;
        int count = 0;
                if (M.length == 0) {
			return longest;
		}
        for(int i = 0;i<M.length;i++) {
        	count = 0;
        	for(int j = 0;j<M[0].length;j++) {
        		if (M[i][j] == 1) {
					count++;
					longest = Math.max(count, longest);
				}else {
					count = 0;
				}
        	}
        }
        for(int i = 0;i<M[0].length;i++) {
        	count = 0;
        	for(int j = 0;j<M.length;j++) {
        		if (M[j][i] == 1) {
        			count++;
					longest = Math.max(count, longest);
				}else {
					count = 0;
				}
        	}
        }
        for(int i=0;i<M.length;i++) {
        	count = 0;
        	for(int j=0,k=i;k<M.length&&j<M[0].length;j++,k++) {
        		if (M[k][j] == 1) {
        			count++;
					longest = Math.max(count, longest);
				}else {
					count = 0;
				}
        	}
        }
        for(int i=0;i<M[0].length;i++) {
        	count = 0;
        	for(int j=i,k=0;k<M.length&&j<M[0].length;j++,k++) {
        		if (M[k][j] == 1) {
        			count++;
					longest = Math.max(count, longest);
				}else {
					count = 0;
				}
        	}
        }
        
        for(int i=0;i<M.length;i++) {
        	count = 0;
        	for(int j=M[0].length-1,k=i;k<M.length&&j>=0;j--,k++) {
        		if (M[k][j] == 1) {
        			count++;
					longest = Math.max(count, longest);
				}else {
					count = 0;
				}
        	}
        }
        for(int i=M[0].length-1;i>=0;i--) {
        	count = 0;
        	for(int j=i,k=0;k<M.length&&j>0;j--,k++) {
        		if (M[k][j] == 1) {
        			count++;
					longest = Math.max(count, longest);
				}else {
					count = 0;
				}
        	}
        }
        return longest;
    }