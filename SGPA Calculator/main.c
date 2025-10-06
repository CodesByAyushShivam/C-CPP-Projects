#include <stdio.h>

int main(){
    // SGPA Calculator
    
    // take the number of subjects as input from the user
    int n;
    printf("Enter the number of subjects: ");
    scanf("%d", &n);
    
    // intiate marks and credits to take input fron user in loop
    int marks, credit;
    
    printf("\nGRADE SCALE:\n");
    printf("90–100: 10 | 80–89: 9 | 70–79: 8 | 60–69: 7 | 50–59: 6 | 35–49: 5 | <35: 0\n");
    
    printf("--------------------------------------------------------------\n\n");
    // initiate variables to be used in calculation
    int sumPoints=0, sumCredits=0, gradePoint;
    for(int i=0; i<n; i++){
        printf("Subject %d \n", i+1);
        printf("\tEnter marks of subject %d: ", i+1);
        scanf("%d", &marks);
        
        printf("\tEnter Credits of subject %d: ", i+1);
        scanf("%d", &credit);
        
        
        // calculate the grade points based on the marks input taken from the user
        if(marks<0 || marks>100){
            printf("You have entered wrong marks\n\n\n");
            i--;
            continue;
        }
        
        else if(marks<=100 && marks>=90)
        gradePoint = 10;
        
        else if(marks<90 && marks>=80)
        gradePoint = 9;
        
        else if(marks<80 && marks>=70)
        gradePoint = 8;
        
        else if(marks<70 && marks>=60)
        gradePoint = 7;
        
        else if(marks<60 && marks>=50)
        gradePoint = 6;
        
        else if(marks<50 && marks>=35)
        gradePoint = 5;
        
        else{
            gradePoint = 0;
            printf("You have failed in this subject \n");
        }
        
        // calculation of sum of points and credits to be used to calculate sgpa after the loop
        sumPoints += credit * gradePoint;
        sumCredits += credit;
        printf("\n\n");
    }
    
    printf("--------------------------------------------------------------\n");
    
    // formula for sgpa
    // 1.00 is multiplied to make type float
    float sgpa = 1.00 * sumPoints/sumCredits;
    
    printf("\nYour SGPA: %.2f", sgpa);
    
    return 0;
}
