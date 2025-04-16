import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ListaDeCompras {
  public static void main (String[] args) {<
    // Criação da lista
    List<String> lista = new ArrayList<>();
   
    // Criação do scanner para ler a entrada do usuário
    Scanner scanner = new Scanner(System.in);
   
    // Solicitar ao usuário que insira itens para a lista
    System.out.println("Digite os itens para a lista de compras. Digite 'fim' para encerrar:");
   
    // Loop para ler itens do usuário
    while (true) {
      System.out.print("Digite um item: ");
      String item = scanner.nextLine();
      if (item.equalsIgnoreCase("fim")) {
        break;  // Encerra o loop quando o usuário digita 'fim'
      }
     
      lista.add(item);  // Adiciona o item à lista
    }
   
    // Exibe a lista de compras
    System.out.println("Lista de compras: " + lista);
   
    // Exemplo de remoção de um item
    System.out.print("Digite um item para remover (ou 'fim' para não remover nada): ");
    String itemRemover = scanner.nextLine();
   
    if (!itemRemover.equalsIgnoreCase("fim") && lista.contains(itemRemover)) {
      lista.remove(itemRemover);  // Remove o item da lista
      System.out.println("Item removido. Lista atualizada: " + lista);
    } else if (!itemRemover.equalsIgnoreCase("fim")) {
      System.out.println("Item não encontrado na lista.");
    }
   
    // Fecha o scanner
    scanner.close();

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Collections;

public class AtvLista {
  public static void main (String[] args) {
   
   List<Integer> lista = new ArrayList<>();
   List<Integer> listaMaior = new ArrayList<>();
   List<Integer> listaMenor = new ArrayList<>();
   List<Integer> listaIgual = new ArrayList<>();
   
   Scanner scan = new Scanner(System.in);
   
   System.out.println("Digite 5 valores de idade ou digite '0' para encerrar:  ");
   
     for (int i = 0; i < 5; i++){
       
          //System.out.print("Digite um valor: \n");
          Integer valor = scan.nextInt();
          if (valor == 0) {
            break;  // Encerra o loop quando o usuário digita 0
          }
        lista.add(valor);
     }
     Integer media = 0;
     media = (lista.get(0)+lista.get(1)+lista.get(2)+lista.get(3)+lista.get(4))/5;
    
     System.out.println("Lista de idades: " + lista);
     
     Collections.sort(lista);
     System.out.println("Lista de idades ordenadas: " + lista);
     
     System.out.print("A média das idades são: " + media + "\n");
     
     for(int verMaior : lista){
    
      if(verMaior > media){
        listaMaior.add(verMaior);
      }
    
    }
     for(int verMenor : lista){
    
      if(verMenor < media){
        listaMenor.add(verMenor);
      }
    
    }
     
    System.out.println("Lista de valores maiores que a média: " + listaMaior + "\n");
    System.out.println("Lista de valores menores que a média: " + listaMenor + "\n");

    System.out.print("Digite um valor a ser removido: \n");
    Integer valorOut = scan.nextInt();
    
    Iterator<Integer> iterator = lista.iterator();
    while (iterator.hasNext()) {
            if (iterator.next().equals(valorOut)) {
                iterator.remove();
            }
        }
  
      System.out.println("Lista de idades: " + lista);
    }
   }