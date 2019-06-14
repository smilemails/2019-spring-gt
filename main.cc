#include <iostream>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"

using namespace std;

//NetworkManager* Disordering(NetworkManager *nm);

string Eulerpath(NetworkManager* EulerGraph);
int degree(Vertex* v);

// create NetworkManager first
NetworkManager *nm = new NetworkManager();

int main(int argc, char** argv){

  string anser;
  
  //read from file
  nm->interpret("input1.txt");
  cout<<"=========================================================="<<endl;
  Eulerpath(nm);
  
  return 0;
}


string Eulerpath(NetworkManager* EulerGraph){  
  string final_path;
  int e_number = 0;
  int v_number = 0;
  NetworkManager *goal_nm = new NetworkManager();
  Edge* origin_elist = EulerGraph->elist;
  Edge* temp_edge;
  Vertex* temp_v;
  Vertex* v_head;
  int counter = 0;
  bool only_one;
  
  while(EulerGraph->elist != NULL){
    e_number++;
    EulerGraph->elist = EulerGraph->elist->next;
  }
  EulerGraph->elist = origin_elist;
  e_number = e_number/2;
  
  for(v_number = 0 ; v_number < 10 ; v_number++){
    if(EulerGraph->vlist[v_number] == NULL){
      break;
    }
  }
  
  Path *path;
  path = new Path();
  
  v_head = EulerGraph->vlist[0];
  goal_nm->add_switch(EulerGraph->vlist[0]->name); 
  final_path = EulerGraph->vlist[0]->name;
  
  EulerGraph->print_all_e();
  
  cout<< EulerGraph->elist <<endl;
  cout<< origin_elist <<endl;
  
  while(counter < e_number){
    cout<< v_head->name <<endl;
    for(int i = 0 ; i < v_number ; i++){
      cout<<"1"<<endl;
      if(origin_elist->head->name == v_head->name){
        cout<<"2"<<endl;
        cout<< origin_elist->head->name << origin_elist->tail->name <<endl;
        
        cout<< origin_elist <<endl;
        
        path->append(origin_elist);
        vector<vector <Edge*>> avail_paths;
        
        
        avail_paths = path->find_paths(origin_elist->head->name , origin_elist->tail->name);
        path->debug();
        
        if(avail_paths.size() != 1){
          cout<<"3"<<endl;
          goal_nm->add_switch(origin_elist->tail->name);
          goal_nm->connect(origin_elist->head->name , origin_elist->tail->name);
          final_path = final_path + " " + origin_elist->tail->name;
          v_head = origin_elist->tail;
          EulerGraph->disconnect(origin_elist->tail->name , origin_elist->head->name);
          EulerGraph->disconnect(origin_elist->head->name , origin_elist->tail->name);
          counter++;
          only_one = 0;
          break;
        }
        else{
          temp_edge = origin_elist;
          only_one = 1;
        }
      }
      
      origin_elist = origin_elist->next;
      
      
      
      
    }
    if(only_one){
      goal_nm->add_switch(temp_edge->tail->name);
      goal_nm->connect(temp_edge->head->name , temp_edge->tail->name);
      final_path = final_path + " " + temp_edge->tail->name;
      v_head = temp_edge->tail;
      EulerGraph->disconnect(temp_edge->tail->name , temp_edge->head->name);
      EulerGraph->disconnect(temp_edge->head->name , temp_edge->tail->name);
      counter++;
    }
    
    cout<< EulerGraph->elist <<endl;
    cout<< origin_elist <<endl; 

    origin_elist = EulerGraph->elist;
    
        cout<< EulerGraph->elist <<endl;
    cout<< origin_elist <<endl; 
   
    EulerGraph->print_all_e();
  }
  
  //while(counter < e_number){
  //  for(int i = 0 ; i < v_number ; i++){
  //    if(EulerGraph->elist->head->name == v_head->name){
  //      avail_paths = path->find_paths(EulerGraph->elist->head->name , EulerGraph->elist->tail->name);
  //      if(avail_paths.size() != 1){
  //        goal_nm->add_switch(EulerGraph->elist->tail->name);
  //        goal_nm->connect(EulerGraph->elist->head->name , EulerGraph->elist->tail->name);
  //        final_path = final_path + " " + EulerGraph->elist->tail->name;
  //        v_head = EulerGraph->elist->tail;
  //        EulerGraph->disconnect(EulerGraph->elist->tail->name , EulerGraph->elist->head->name);
  //        EulerGraph->disconnect(EulerGraph->elist->head->name , EulerGraph->elist->tail->name);
  //        counter++;
  //        only_one = 0;
  //        break;
  //      }
  //      else{
  //        temp_edge = EulerGraph->elist;
  //        only_one = 1;
  //      }
  //    }
  //    EulerGraph->elist = EulerGraph->elist->next;
  //  }
  //  if(only_one){
  //    goal_nm->add_switch(temp_v->name);
  //    goal_nm->connect(temp_edge->head->name , temp_edge->tail->name);
  //    final_path = final_path + " " + temp_edge->tail->name;
  //    v_head = temp_edge->tail;
  //    EulerGraph->disconnect(temp_edge->tail->name , temp_edge->head->name);
  //    EulerGraph->disconnect(temp_edge->head->name , temp_edge->tail->name);
  //    counter++;
  //  }
  //  EulerGraph->elist = origin_elist;
  //}

  cout<<final_path<<endl;
  cout<<counter<<endl;
  
  return final_path;
}

int degree(Vertex* v){
  int degree = 0;
  
  while(nm->elist != NULL){
    if(nm->elist->head->name == v->name){
      degree++;
    }
    nm->elist = nm->elist->next;
  }
  
  return degree;
}


















//NetworkManager* Disordering(NetworkManager* nm){
//  int v_number;
//  
//  NetworkManager *new_nm = nm; 
//  
//  new_nm->print_all_v();
//  new_nm->print_all_e();
//  
//  for(v_number = 0 ; v_number < 10 ; v_number++){
//    if(new_nm->vlist[v_number] == NULL){
//      break;
//    }
//  }
//  
//  for(int v1 = 0 ; v1 < v_number ; v1++){
//    for(int v2 = v1 + 1 ; v2 < v_number ; v2++){
//      if(new_nm->connected( (new_nm->vlist[v1]->name),(new_nm->vlist[v2]->name)));
//    }
//  }
//  
//  return new_nm;
//}