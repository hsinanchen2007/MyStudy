- [``public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int[] result = new int[queries.length];
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            if (isDouble(A[i])){
                sum += A[i];
            }
        }
        for (int i = 0; i < queries.length; i++) {
            if (isDouble(A[queries[i][1]]) && isDouble(queries[i][0])){
                sum += queries[i][0];
            }else if (isDouble(A[queries[i][1]])){
                sum -= A[queries[i][1]];
            }else if (!isDouble(A[queries[i][1]]) && !isDouble(queries[i][0])){
                sum += (queries[i][0] + A[queries[i][1]]);
            }
            A[queries[i][1]] += queries[i][0];
            result[i] = sum;
        }
        return result;
    }

    public boolean isDouble(int num){
        if (num % 2 == 0){
            return true;
        }
        return false;
    }``]()