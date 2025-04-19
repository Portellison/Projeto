# 🍔 Sistema de Pagamento da Lanchonete

Este é um sistema simples feito em linguagem C para gerenciamento de funcionários e geração de pagamentos em uma lanchonete fictícia. O projeto foi desenvolvido como exercício para a disciplina de Linguagem de Programação.

## 📋 Funcionalidades

- Adicionar funcionários por setor:
  - Frente de atendimento
  - Cozinha
  - Entregas
- Listar todos os funcionários por setor
- Remover funcionários por setor
- Gerar lista de pagamentos:
  - Frente: valor base R$70,00
  - Cozinha: valor base R$80,00
  - Entregadores: R$10,00 por entrega + R$1,00 por VN
  - Opção de desconto manual para todos

## 💾 Armazenamento

O sistema utiliza arquivos `.txt` para armazenar os dados dos funcionários:
- `frente.txt`
- `cozinha.txt`
- `entregas.txt`
- `pagamentos.txt` (gerado ao final do processo de cálculo)

## 📌 Como usar

1. Compile o código com um compilador C (como GCC):
2. Execute o programa:

3. Use o menu para gerenciar os funcionários e calcular os pagamentos.

## 🛠 Estrutura do Projeto


## ✍️ Autor

Feito por [@Portellison](https://github.com/Portellison) 💻

## 📚 Observações

- Este sistema é totalmente feito com base em leitura e escrita de arquivos simples.
- Não usa banco de dados nem interface gráfica.
- Ideal para treinar lógica de programação, manipulação de arquivos e organização de código em C.
