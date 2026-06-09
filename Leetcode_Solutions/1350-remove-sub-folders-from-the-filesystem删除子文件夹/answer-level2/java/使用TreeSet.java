// TreeSet包含的视为相等

public static List<String> removeSubfolders(String[] folder) {

        List<String> folders = new LinkedList<>();

        for (String s : folder) {
            folders.add(s);
        }

        Collections.sort(folders);
        Set fSet = new TreeSet(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                // /a/b   /a/bc
                if (o1.contains(o2+"/")) {
                    return 0;
                } else {
                    return o1.compareTo(o2);
                }

            }

        });

        fSet.addAll(folders);

        List<String> result = new LinkedList<>(fSet);

        return result;
    }