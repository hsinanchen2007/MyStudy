```
public static int numIslands(char[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        ArrayList<String> rowCol = new ArrayList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != '0') {
                    String s = "" + i + "," + j;
                    rowCol.add(s);
                }
            }
        }
        if (rowCol.size() == 0) {
            return 0;
        }
        int[] Sum = new int[1];
        Stack<String> stack = new Stack<>();
        String str = rowCol.get(0);
        stack.push(str);
        Sum[0] = 0;
        calculate(rowCol, Sum, grid, stack);
        System.out.println(Sum[0]);
        return Sum[0];
    }

    public static void calculate(ArrayList<String> rowCol, int[] Sum, char[][] grid, Stack<String> stack) {
        if (rowCol.size() == 0) {
            return;
        }
//        Stack<String> total = new Stack<>();
        ArrayList<String> list = new ArrayList<>();
        list.add(stack.peek());
        while (!stack.isEmpty()) {
            String str = stack.pop();


            int curRow = Integer.parseInt(str.split(",")[0]);
            int curCol = Integer.parseInt(str.split(",")[1]);
            String s = "" + curRow + "," + curCol;
            for (int i = 0; i < rowCol.size(); i++) {
                if (rowCol.get(i).equals(s)) {
                    rowCol.remove(i);
//                    System.out.println(s + " rowCol:" + rowCol.size());
                    break;
                }

            }
            if (curRow + 1 < grid.length && grid[curRow + 1][curCol] == '1') {
                String s2 = "" + (curRow + 1) + "," + curCol;
                if (!(list.contains(s2))) {
                    stack.push(s2);
                    list.add(s2);
                }


            }
            if (curCol + 1 < grid[0].length && grid[curRow][curCol + 1] == '1') {
                String s2 = "" + curRow + "," + (curCol + 1);
                if (!(list.contains(s2))) {
                    stack.push(s2);
                    list.add(s2);
                }
            }

            if (curCol - 1 >= 0 && grid[curRow][curCol - 1] == '1') {
                String left = "" + curRow + "," + (curCol - 1);
                if (!(list.contains(left))) {
                    stack.push(left);
                    list.add(left);
                }
            }
            if (curRow - 1 >= 0 && grid[curRow - 1][curCol] == '1') {
                String left = "" + (curRow - 1) + "," + curCol;
                if (!(list.contains(left))) {
                    stack.push(left);
                    list.add(left);

                }
            }
        }
        if (rowCol.size() > 0) {
            Sum[0] += 1;
            stack.push(rowCol.get(0));
            calculate(rowCol, Sum, grid, stack);
        } else {
            Sum[0] += 1;
            return;
        }

    }
```
