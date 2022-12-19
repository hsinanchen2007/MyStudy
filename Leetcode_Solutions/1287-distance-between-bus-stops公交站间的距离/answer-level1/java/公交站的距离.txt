        int[] sum = new int[distance.length];
        for (int i = 1;i < distance.length;i++) sum[i] = sum[i - 1] + distance[i - 1];
        int total = sum[distance.length - 1] + distance[distance.length - 1];
        int len = Math.abs(sum[start] - sum[destination]);
        return Math.min(total - len, len);