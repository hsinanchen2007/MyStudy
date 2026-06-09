
    public List<Integer> spiralOrder(int[][] matrix) {
    	int m=0;
    	int n=0;
    	List<Integer> result = new ArrayList<Integer>();
        for(int i=0;i<matrix.length*matrix[0].length;) {
        	//向右
        	while(n<matrix[0].length&&matrix[m][n]!=Integer.MAX_VALUE) {
        		result.add(matrix[m][n]);
        		matrix[m][n]=Integer.MAX_VALUE;
        		n++;
        		i++;
        	}
        	n--;
        	m++;
        	//向下
        	while(m<matrix.length&&matrix[m][n]!=Integer.MAX_VALUE) {
        		result.add(matrix[m][n]);
        		matrix[m][n]=Integer.MAX_VALUE;
        		m++;
        		i++;
        	}
        	m--;
        	n--;
        	//想左
        	while(n>=0&&matrix[m][n]!=Integer.MAX_VALUE) {
        		result.add(matrix[m][n]);
        		matrix[m][n]=Integer.MAX_VALUE;
        		n--;
        		i++;
        	}
        	n++;
        	m--;
        	//向上
        	while(m>=0&&matrix[m][n]!=Integer.MAX_VALUE) {
        		result.add(matrix[m][n]);
        		matrix[m][n]=Integer.MAX_VALUE;
        		m--;
        		i++;
        	}
        	m++;
        	n++;
        }
    	
    	
    	return result;
    }