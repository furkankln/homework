import StudentPackage.Student;

public class furkankılın {

    static Student grades[] = new Student[200];
    static int index1 = 0;





    public static void sort() {
        for (int i = 0; i < index1 - 1; i++) {
            int index = i;
            for (int j = i + 1; j < index1; j++)
                if (grades[j].grade > grades[index].grade)
                    index = j;
                else if (grades[j].grade == grades[index].grade) {
                    if (grades[j].number < grades[index].number) {
                        index = j;
                    }
                }





            Student sortsmalltobig = grades[index];
            grades[index] = grades[i];
            grades[i] = sortsmalltobig;
        }
    }




    public static void add(int number, int grade) {
        grades[index1] = new Student(number, grade, index1);
        index1++;
        sort();
    }




    public static void del(int index) {
        int index2 = index;
        for (int c = 0; c < index1; c++) {
            if (index2 == grades[c].index) {
                int cBuff = c;
                for (; cBuff < index1 - 1; cBuff++) {
                    grades[cBuff] = grades[cBuff + 1];
                }
                grades[index1 - 1] = null;
                index1--;
                break;
            }
        }
        index2++; 
        for (; index2 < index1; index2++)
            for (int f = 0; f < index1; f++) {
                if (grades[f].index == index2) {
                    grades[f].index = grades[f].index - 1;
                }
            }
        
        
    }
   

    
    public static void change(int index, int changedgrade) {
        grades[index].grade = changedgrade; 
        sort();
    }




    public static void print() {
        for (int i = 0; i < index1; i++) {
            System.out.print(grades[i].index + "     " );
            System.out.print(grades[i].number + "     ");
            System.out.println(grades[i].grade);
        }

    }



    public static void main(String[] args) {

        add(18060311, 40);

        add(20060045, 50);

        add(19061091, 75);

        add(20060134, 90);

        add(20060678, 40);

        add(18061086, 75);

        add(20060032, 50);

        add(20060067, 60);

        add(19060456, 60);

        add(18060245, 75);

        add(20060110, 40);

        add(20060234, 90);

        add(20060141, 60);

        add(20060011, 50);

        add(20060012, 60);

        

        
        

        
        print();

    }

}