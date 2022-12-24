#include <iostream>

// Completely written by LordOfWizard himself, 
// This code is made for educational purpose only
// Redistribution / selling of this code is not allowed.
/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and displaya) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/

class Student{
    public:
    int roll;
    Student * next;
    Student(int roll){
        this-> roll = roll;
    }
};

class List{
    public:
    Student * head;

    List(){
        this->head = NULL;
    }

    void add(int roll){
        Student * stud = new Student(roll);
        stud->next = this->head;
        this->head = stud;
    }

    void show(){
        Student * current = this->head;
        while(current!= NULL){
            std::cout << current ->roll << " ";
            current=current->next;
        }
        std::cout << std::endl;
    }
    int cur_elem(){
        return head->roll;
    }
    Student * cur_head(){
        return this->head;
    }
};

List intersection(List * vanilla, List * butterscotch){
    Student * current_van = vanilla->cur_head();
    Student * current_butter = butterscotch->cur_head();
    List result;
    while(current_van != NULL){
        current_butter = butterscotch->cur_head();
        while(current_butter != NULL){
            if(current_van->roll == current_butter->roll) result.add(current_van->roll);
                current_butter = current_butter->next;
            }
        current_van = current_van->next;
        }
    return result;        
}

bool present(int num, List * list){
    List * temp_list = list;
    while(temp_list->cur_head() != NULL){
        if (temp_list->cur_head()->roll == num) return true;
        temp_list->head = temp_list->cur_head()->next;
    }
    return false;
}

List union_list(List * vanilla, List * butterscotch){
    List result = *butterscotch;
    List * temp_van = vanilla;
    while(temp_van->cur_head() != NULL){
        if (present(temp_van->cur_head()->roll,butterscotch) == false){
            result.add(temp_van->cur_head()->roll);
        }
        temp_van->head = temp_van->cur_head()->next;
    }
    return result;
}



int main(){
    List vanilla;
    int van_len;
    std::cout << "Please enter the ROLL NOs of students who like Vanilla";
    std::cin >> van_len;
    for(int i = 0; i < van_len; i++){
        int num;
        std::cin >> num;
        vanilla.add(num);
    }

    List butterscotch;
    int butter_len;
    std::cout << "Please enter the ROLL NOs of students who like Vanilla";
    std::cin >> butter_len;
    for(int i = 0; i < butter_len; i++){
        int num;
        std::cin >> num;
        butterscotch.add(num);
    }

    List inter = intersection(&vanilla,&butterscotch);
    inter.show();
    
    List uni = union_list(&vanilla, &butterscotch);
    uni.show();
    return 0;
}
